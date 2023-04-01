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

#pragma once

#include <system_error>
#include <type_traits>

//! Executes a LMDB command, and returns errors via `lmdb::error` enum.
#define MONERO_LMDB_CHECK(...)         \
    do                                 \
    {                                  \
        const int err = __VA_ARGS__ ;  \
        if (err)                       \
            return {lmdb::error(err)}; \
    } while (0)

namespace lmdb
{
    //! Tracks LMDB error codes.
    enum class error : int
    {
        // 0 is reserved for no error, as per expect<T>
        // All other errors are the values reported by LMDB
    };

    std::error_category const& error_category() noexcept;

    inline std::error_code make_error_code(error value) noexcept
    {
        return std::error_code{int(value), error_category()};
    }
}

namespace std
{
    template<>
    struct is_error_code_enum<::lmdb::error>
      : true_type
    {};
}
