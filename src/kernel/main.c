__attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
	0x1BADB002,
	0,
	-(0x1BADB002)
};


#include "gdt.h"
#include "idt.h"

#include "../libs/asm.h"
#include "../libs/tools.h"

#include "../drivers/drivers.h"


int kmain(){

    gdt_init();
    interrupt_init();

    register_drivers();
    devman_devices_find();

    while(1){

    }

}
