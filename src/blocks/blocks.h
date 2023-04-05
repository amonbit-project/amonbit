#ifndef SRC_BLOCKS_BLOCKS_H_
#define SRC_BLOCKS_BLOCKS_H_

#include "crypto_prefs.h"
#include "span.h"

namespace blocks
{
    const epee::span<const unsigned char> GetCheckpointsData(crypto::network_type network);
}

#endif 
/* SRC_BLOCKS_BLOCKS_H_ */
