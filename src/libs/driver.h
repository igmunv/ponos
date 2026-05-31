#pragma once

#include "device_common.h"


typedef int probe_func_prot(void*);


struct driver_info{
    unsigned int id;
    struct device_desc dev_desc;
    void* probe;
    void** funcs;
};
