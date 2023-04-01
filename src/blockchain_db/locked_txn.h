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

namespace cryptonote
{
    // This class is meant to create a batch when none currently exists.
    // If a batch exists, it can't be from another thread, since we can
    // only be called with the txpool lock taken, and it is held during
    // the whole prepare/handle/cleanup incoming block sequence.
    class LockedTXN {
    public:
      LockedTXN(BlockchainDB &db): m_db(db), m_batch(false), m_active(false) {
        m_batch = m_db.batch_start();
        m_active = true;
      }
      void commit() { try { if (m_batch && m_active) { m_db.batch_stop(); m_active = false; } } catch (const std::exception &e) { MWARNING("LockedTXN::commit filtering exception: " << e.what()); } }
      void abort() { try { if (m_batch && m_active) { m_db.batch_abort(); m_active = false; } } catch (const std::exception &e) { MWARNING("LockedTXN::abort filtering exception: " << e.what()); } }
      ~LockedTXN() { abort(); }
    private:
      BlockchainDB &m_db;
      bool m_batch;
      bool m_active;
    };
}
