#pragma once


enum DEV_TYPES{
    PCI,
    LEGACY,
    VIRTUAL
};

struct device_desc{
    enum DEV_TYPES type;
    unsigned int class;
    unsigned int subclass;
};


struct device_info{
    unsigned int id;
    struct device_desc desc;
    void* data;
    struct driver_info* driver;
};

enum DEV_LEGACY_CLASSES{
    LEG_KEYBOARD,
    LEG_MOUSE,
    LEG_PIT
};
