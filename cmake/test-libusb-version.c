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

#include <libusb.h>

#define UNUSED(expr) (void)(expr)

int main(int argc, char *argv[]) {
  libusb_device **devs;
  libusb_context *ctx = NULL;

  int r = libusb_init(&ctx); UNUSED(r);
  ssize_t cnt = libusb_get_device_list(ctx, &devs); UNUSED(cnt);

  struct libusb_device_descriptor desc;
  r = libusb_get_device_descriptor(devs[0], &desc); UNUSED(r);
  uint8_t bus_id = libusb_get_bus_number(devs[0]); UNUSED(bus_id);
  uint8_t addr = libusb_get_device_address(devs[0]); UNUSED(addr);

  uint8_t tmp_path[16];
  r = libusb_get_port_numbers(devs[0], tmp_path, sizeof(tmp_path));
  UNUSED(r);
  UNUSED(tmp_path);

  libusb_free_device_list(devs, 1);
  libusb_exit(ctx);
}
