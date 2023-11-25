#include "./src/blocks/Blockchain.h"
#include <iostream>

int main() {
    Blockchain myBlockchain;

    myBlockchain.addBlock("Block 1 Data");
    myBlockchain.addBlock("Block 2 Data");

    // Check if the blockchain is valid
    if (myBlockchain.isChainValid()) {
        std::cout << "Blockchain is valid.\n";
    } else {
        std::cout << "Blockchain is not valid.\n";
    }

    return 0;
}
