#pragma once

#include "device_common.h"
#include "driver.h"




struct device_info{
    unsigned int id;
    struct device_desc desc;
    void* data;
    struct driver_info* driver;
};


