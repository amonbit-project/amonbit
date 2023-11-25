//
// Created by agastronics on 11/25/2023.
//

#ifndef AMONBIT_BLOCK_H
#define AMONBIT_BLOCK_H

#include <ctime>
#include <string>

class Block {
public:
    int index;
    std::string previousHash;
    time_t timestamp;
    std::string data;
    std::string hash;

    Block(int index, const std::string& previousHash, const std::string& data);
    std::string calculateHash() const;
};

#endif //AMONBIT_BLOCK_H
