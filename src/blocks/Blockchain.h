//
// Created by agast on 11/25/2023.
//

#ifndef AMONBIT_BLOCKCHAIN_H
#define AMONBIT_BLOCKCHAIN_H

#include "Block.h"
#include <vector>

class Blockchain {
private:
    std::vector<Block> chain;

public:
    Blockchain();
    const Block& getLatestBlock() const;
    void addBlock(const std::string& data);
    bool isChainValid() const;
};

#endif //AMONBIT_BLOCKCHAIN_H
