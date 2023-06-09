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

#include <string>
#include <iostream>
#include <google/protobuf/message.h>
#include <google/protobuf/unknown_field_set.h>
#include "test-protobuf.pb.h"

int main(int argc, char *argv[]) {
  google::protobuf::UnknownFieldSet ufs;
  ufs.ClearAndFreeMemory();

  Success sc;
  sc.set_message("test");
  sc.SerializeToOstream(&std::cerr);
  return 0;
}
