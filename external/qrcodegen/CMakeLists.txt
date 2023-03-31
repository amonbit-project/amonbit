# Copyright (c) 2023, The Amonbit Project
#
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code: 
#    - Must retain the above copyright notice
#    - Must retain this list of conditions
#    - Must include the following disclaimer
#
# 2. Redistributions in binary form: 
#    - Must reproduce the above copyright notice
#    - Must reproduce this list of conditions
#    - Must include the following disclaimer in the documentation and/or other materials provided with the distribution.

project(libqrcodegen)

add_library(qrcodegen STATIC QrCode.cpp)
set_target_properties(qrcodegen PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(qrcodegen PROPERTIES CXX_STANDARD 11)

target_include_directories(qrcodegen PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR})
