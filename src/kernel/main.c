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
#include "../libs/prints.h"
#include "../libs/memory.h"
#include "../libs/program.h"

#include "../drivers/drivers.h"

#include "device_manager.h"
#include "driver_manager.h"
#include "program_manager.h"

#include "../api/kapi.h"

int kmain(){

    gdt_init();
    interrupt_init();

    register_drivers();
    devman_devices_find();

    progman_find_programs();


    // All Programs:

    _clear();
    struct program* all_programs = progman_programs_get();
    unsigned int program_count = progman_program_count_get();

    for (unsigned int i = 0; i < program_count; i++){

        struct program prog = all_programs[i];
        _print(prog.name, 16);
        _print("\n", 1);
    }


    progman_program_run(0);


    // unsigned char ata_buffer[512] = {};
    // _ata_read_sector((unsigned int)ata_buffer,0,1);
    //
    // print_bytes(ata_buffer, 24);
    // _print("\n", 1);
    // _print(ata_buffer, 30);


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
