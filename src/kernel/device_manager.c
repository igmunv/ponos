#include "device_manager.h"
#include "driver_manager.h"
#include "../api/kapi.h"

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

    _print("Dev Man: register new device\n", 50);

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

struct device_info* devman_device_get_first_by_class(enum DEV_TYPES type, unsigned int class){
    for (int i = 0; i < DEVICE_COUNT; i++){
        struct device_info* dev = &DEVICES[i];
        if (dev->desc.type == type && dev->desc.class == class)
            return dev;
    }
    return 0;
}

void devman_devices_find_legacy(){
    struct device_desc vga_tm_desc = {LEGACY, LEG_VGA_TM, 0};
    devman_device_reg(&vga_tm_desc, 0);

    struct device_desc keyboard_desc = {LEGACY, LEG_KEYBOARD, 0};
    devman_device_reg(&keyboard_desc, 0);

    struct device_desc ata_desc = {LEGACY, LEG_ATA, 0};
    devman_device_reg(&ata_desc, 0);


}

void devman_devices_find_virtual(){

}

void devman_devices_find_pci(){

}

void devman_devices_find(){
    devman_devices_find_legacy();
    devman_devices_find_pci();
    devman_devices_find_virtual();
}
