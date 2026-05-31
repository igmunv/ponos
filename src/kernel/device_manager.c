#include "device_manager.h"
#include "driver_manager.h"

unsigned short DEVICE_COUNT = 0;

unsigned short devman_device_reg(struct device_desc* desc, void* data){

    if (DEVICE_COUNT >= MAX_DEVICE_COUNT) return 0;

    struct device_info dev_info;

    dev_info.id = DEVICE_COUNT;
    dev_info.desc = *desc;
    dev_info.data = data;
    dev_info.driver = drvman_driver_get(desc, data);

    DEVICES[DEVICE_COUNT] = dev_info;
    DEVICE_COUNT++;


}

struct device_info* devman_device_get(){
    return &DEVICES;
}

unsigned short devman_device_get_count(){
    return DEVICE_COUNT;
}

struct device_info* devman_device_get_by_type(enum DEV_TYPES type){

}

struct device_info* devman_device_get_by_class(enum DEV_TYPES type, unsigned int class){

}

struct device_info* devman_device_get_by_subclass(enum DEV_TYPES type, unsigned int class, unsigned int subclass){

}

void devman_devices_find(){
    struct device_desc keyboard_desc = {LEGACY, LEG_KEYBOARD, 0};
    devman_device_reg(&keyboard_desc, 0);
}
