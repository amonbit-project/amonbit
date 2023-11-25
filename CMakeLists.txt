cmake_minimum_required(VERSION 3.26)
project(amonbit)

set(CMAKE_CXX_STANDARD 23)

add_executable(amonbit main.cpp
        src/blocks/block.h
        src/blocks/block.cpp
        src/blocks/Blockchain.h
        src/blocks/Blockchain.cpp)
