__attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
	0x1BADB002,
	0,
	-(0x1BADB002)
};


#include "gdt.h"
#include "idt.h"

#include "../libs/asm.h"
#include "../libs/driver.h"
#include "../libs/device.h"
#include "../libs/device_common.h"
#include "../libs/string.h"

#include "../drivers/drivers.h"

#include "device_manager.h"
#include "driver_manager.h"

#include "../api/kapi.h"




int kmain(){

    gdt_init();
    interrupt_init();

    register_drivers();
    devman_devices_find();


    unsigned char* keyboard_buffer = _get_keyboard_buffer();
    unsigned char* keyb_buffer_loc = _get_keyboard_buffer_loc();
    unsigned char local_buffer_loc = *keyb_buffer_loc;

    while(1){

        if (local_buffer_loc != *keyb_buffer_loc){
            unsigned char symbol = scancode_to_ascii(keyboard_buffer[local_buffer_loc], 0);
            unsigned char tsym[] = {symbol, '\0'};
            _print(tsym, 1);
            local_buffer_loc = (local_buffer_loc+1) % 16;
        }

    }

}
