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

#include "table.h"

namespace lmdb
{
    expect<MDB_dbi> table::open(MDB_txn& write_txn) const noexcept
    {
        MONERO_PRECOND(name != nullptr);

        MDB_dbi out;
        MONERO_LMDB_CHECK(mdb_dbi_open(&write_txn, name, flags, &out));
        if (key_cmp && !(flags & MDB_INTEGERKEY))
            MONERO_LMDB_CHECK(mdb_set_compare(&write_txn, out, key_cmp));
        if (value_cmp && !(flags & MDB_INTEGERDUP))
            MONERO_LMDB_CHECK(mdb_set_dupsort(&write_txn, out, value_cmp));
        return out;
    }
}
