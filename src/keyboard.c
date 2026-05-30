#include "keyboard.h"

#include "asm.h"
#include "tools.h"


unsigned char get_char_by_scancode(unsigned char scancode){

    switch(scancode){
        case 0x02: return '1';
        case 0x03: return '2';
        case 0x04: return '3';
        case 0x05: return '4';
        case 0x06: return '5';
        default: return 'x';
    }

}

static pos = 0;

void keyboard_intr_handler(){

    unsigned char scancode = inb(0x60);

    print_char(get_char_by_scancode(scancode), pos);
    pos++;
    // print_char('a', 1);
    // print_char('t', 2);
    // print_char('s', 3);


    outb(0x20,0x20);

}
