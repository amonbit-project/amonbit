//
// Created by agastronics on 11/25/2023.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    // Create the genesis block
    chain.emplace_back(0, "0", "Genesis Block");
}

const Block& Blockchain::getLatestBlock() const {
    return chain.back();
}

void Blockchain::addBlock(const std::string& data) {
    int index = chain.size();
    const Block& previousBlock = getLatestBlock();
    chain.emplace_back(index, previousBlock.hash, data);
}

bool Blockchain::isChainValid() const {
    for (int i = 1; i < chain.size(); ++i) {
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];

        // Check if the hash is valid
        if (currentBlock.hash != currentBlock.calculateHash()) {
            return false;
        }

        // Check if the previousHash matches
        if (currentBlock.previousHash != previousBlock.hash) {
            return false;
        }
    }

    return true;
}
