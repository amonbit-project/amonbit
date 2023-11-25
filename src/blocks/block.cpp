//
// Created by agastronics on 11/25/2023.
//

#include "Block.h"
#include <openssl/sha.h>

Block::Block(int index, const std::string& previousHash, const std::string& data)
        : index(index), previousHash(previousHash), data(data) {
    timestamp = std::time(nullptr);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::string dataToHash = std::to_string(index) + previousHash + std::to_string(timestamp) + data;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(dataToHash.c_str()), dataToHash.length(), hash);

    std::string hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        char hex[3];
        snprintf(hex, sizeof(hex), "%02x", hash[i]);
        hashString += hex;
    }
    return hashString;
}
