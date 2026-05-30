__attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
	0x1BADB002,
	0,
	-(0x1BADB002)
};


#include "gdt.h"
#include "idt.h"

#include "asm.h"
#include "tools.h"

#include "keyboard.h"


void test(){
    register_interrupt_handler(33, keyboard_intr_handler_asm);
}


int kmain(){

    gdt_init();
    interrupt_init();

    test();

    while(1){

    }

}
