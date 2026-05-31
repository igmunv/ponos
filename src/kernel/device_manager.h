#pragma once

#define MAX_DEVICE_COUNT 256

#include "../libs/device.h"

unsigned short DEVICE_COUNT;
struct device_info DEVICES[MAX_DEVICE_COUNT];

unsigned short devman_device_reg(struct device_desc* desc, void* data);

struct device_info* devman_device_get();

unsigned short devman_device_get_count();

struct device_info* devman_device_get_by_type(enum DEV_TYPES type);

struct device_info* devman_device_get_by_class(enum DEV_TYPES type, unsigned int class);

struct device_info* devman_device_get_by_subclass(enum DEV_TYPES type, unsigned int class, unsigned int subclass);

void devman_devices_find();
