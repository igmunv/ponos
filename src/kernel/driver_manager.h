#pragma once

#define MAX_DRIVER_COUNT 256

#include "../libs/driver.h"

unsigned short DRIVER_COUNT;
struct driver_info DRIVERS[MAX_DRIVER_COUNT];

void drvman_driver_reg(struct device_desc dev_desc, void* probe, void* funcs);

struct driver_info* drvman_driver_get(struct device_desc* desc, void* data);
