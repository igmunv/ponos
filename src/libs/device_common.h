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

enum DEV_LEGACY_CLASSES{
    LEG_KEYBOARD,
    LEG_MOUSE,
    LEG_PIT,
    LEG_VGA_TM
};
