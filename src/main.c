__attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
	0x1BADB002,
	0,
	-(0x1BADB002)
};


#include "gdt.h"


int kmain(){

    gdt_init();

    while(1){

    }

}
