#include "driver_manager.h"

unsigned short DRIVER_COUNT = 0;

void drvman_driver_reg(struct device_desc dev_desc, void* probe, void* funcs){

    if (DRIVER_COUNT >= MAX_DRIVER_COUNT) return 0;

    struct driver_info driver;
    driver.dev_desc = dev_desc;
    driver.probe = probe;
    driver.funcs = funcs;

    DRIVERS[DRIVER_COUNT] = driver;
    DRIVER_COUNT++;
}

struct driver_info* drvman_driver_get(struct device_desc* desc, void* data){

    if (!desc) return 0;

    for (int i = 0; i < DRIVER_COUNT; i++){

        struct driver_info* driver = &DRIVERS[i];
        if (!driver) continue;
        struct device_desc* drv_desc = &driver->dev_desc;

        probe_func_prot* driver_probe = (probe_func_prot*)(driver->probe);

        if (desc->type == drv_desc->type && desc->class == drv_desc->class && desc->subclass == drv_desc->subclass){
            if (driver_probe(data)) return driver;
            else continue;
        }

    }

    return 0;

}


