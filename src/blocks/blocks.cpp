#include "blocks.h"

#include <unordered_map>

extern const unsigned char checkpoints[];
extern const size_t checkpoints_len;
extern const unsigned char corenet_blocks[];
extern const size_t corenet_blocks_len;
extern const unsigned char testnet_blocks[];
extern const size_t testnet_blocks_len;

namespace blocks
{

  const std::unordered_map<crypto::network_type, const epee::span<const unsigned char>, std::hash<size_t>> CheckpointsByNetwork = {
    {crypto::network_type::MAINNET, {checkpoints, checkpoints_len}},
    {crypto::network_type::TESTNET, {testnet_blocks, testnet_blocks_len}},
    {crypto::network_type::CORENET, {corenet_blocks, corenet_blocks_len}}
  };

  const epee::span<const unsigned char> GetCheckpointsData(crypto::network_type network)
  {
    const auto it = CheckpointsByNetwork.find(network);
    if (it != CheckpointsByNetwork.end())
    {
      return it->second;
    }
    return nullptr;
  }

}
