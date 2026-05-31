#include "kapi.h"


void _print(unsigned char* text, unsigned char size){
    struct device_info* vga_tm_dev = devman_device_get_first_by_class(LEGACY, LEG_VGA_TM);
    if (!vga_tm_dev) return;
    struct driver_info* vga_rm_drv = vga_tm_dev->driver;
    if (vga_rm_drv){
        void (*print_text)(unsigned char*, unsigned short) = (void (*)(unsigned char*, unsigned short))(vga_tm_dev->driver->funcs[0]); // vga_tm_print_text(unsigned char* text, unsigned short size);
        print_text(text, size);
    }
}

void _clear(){
    struct device_info* vga_tm_dev = devman_device_get_first_by_class(LEGACY, LEG_VGA_TM);
    if (!vga_tm_dev) return;
    struct driver_info* vga_rm_drv = vga_tm_dev->driver;
    if (vga_rm_drv){
        void (*cls)(void) = (void (*)(void))(vga_tm_dev->driver->funcs[1]);
        cls();
    }
}

unsigned char* _get_keyboard_buffer(){
    struct device_info* keyb_dev = devman_device_get_first_by_class(LEGACY, LEG_KEYBOARD);
    if (!keyb_dev) return;
    struct driver_info* keyb_drv = keyb_dev->driver;
    if (keyb_drv){
        unsigned char* (*get_buffer)(void) = (unsigned char* (*)(void))(keyb_dev->driver->funcs[0]);
        return get_buffer();
    }
}

unsigned char* _get_keyboard_buffer_loc(){
    struct device_info* keyb_dev = devman_device_get_first_by_class(LEGACY, LEG_KEYBOARD);
    if (!keyb_dev) return;
    struct driver_info* keyb_drv = keyb_dev->driver;
    if (keyb_drv){
        unsigned char* (*get_buffer_loc)(void) = (unsigned char* (*)(void))(keyb_dev->driver->funcs[1]);
        return get_buffer_loc();
    }
}
