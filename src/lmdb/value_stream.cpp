// Copyright (c) 2023, The Amonbit Project

// All rights reserved.

// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code: 
//     - Must retain the above copyright notice
//     - Must retain this list of conditions
//     - Must include the following disclaimer

// 2. Redistributions in binary form: 
//     - Must reproduce the above copyright notice
//     - Must reproduce this list of conditions
//     - Must include the following disclaimer in the documentation and/or other materials provided with the distribution.

// 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

#include "value_stream.h"

#include <stdexcept>

#include "common/expect.h"
#include "lmdb/error.h"
#include "lmdb/util.h"

namespace lmdb
{
    namespace stream
    {
        mdb_size_t count(MDB_cursor* cur)
        {
            mdb_size_t out = 0;
            if (cur)
            {
                const int rc = mdb_cursor_count(cur, &out);
                if (rc)
                    MONERO_THROW(lmdb::error(rc), "mdb_cursor_count");
            }
            return out;
        }

        std::pair<epee::span<const std::uint8_t>, epee::span<const std::uint8_t>>
        get(MDB_cursor& cur, MDB_cursor_op op, std::size_t key, std::size_t value)
        {
            MDB_val key_bytes{};
            MDB_val value_bytes{};
            const int rc = mdb_cursor_get(&cur, &key_bytes, &value_bytes, op);
            if (rc)
            {
                if (rc == MDB_NOTFOUND)
                    return {};
                MONERO_THROW(lmdb::error(rc), "mdb_cursor_get");
            }

            if (key && key != key_bytes.mv_size)
                MONERO_THROW(lmdb::error(MDB_BAD_VALSIZE), "mdb_cursor_get key");

            if (value && (value_bytes.mv_size % value != 0 || value_bytes.mv_size == 0))
                MONERO_THROW(lmdb::error(MDB_BAD_VALSIZE), "mdb_cursor_get value");

            return {lmdb::to_byte_span(key_bytes), lmdb::to_byte_span(value_bytes)};
        }
    }
}

