#pragma once

#include "../kernel/driver_manager.h"

#define VGA_BUFFER 0xB8000

struct device_desc VGA_TM_DEV_DESC;
void* VGA_TM_FUNC[];
unsigned int vga_tm_probe(void* data);
