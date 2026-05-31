#include "keyboard.h"

#include "../libs/asm.h"

#include "../kernel/driver_manager.h"
#include "../kernel/idt.h"

struct device_desc KEYBOARD_DEV_DESC = {LEGACY, LEG_KEYBOARD, 0};

unsigned char* keyboard_buffer_get();
unsigned char* keyboard_buffer_loc_get();

void* KEYBOARD_FUNC[] = {
    keyboard_buffer_get,
    keyboard_buffer_loc_get
};

unsigned char KEYBOARD_SHIFT_STATE = 0;

unsigned char BUFFER[BUFFER_SIZE];
unsigned char BUFFER_LOCATE = 0;


unsigned char* keyboard_buffer_get(){
    return &BUFFER;
}

unsigned char* keyboard_buffer_loc_get(){
    return &BUFFER_LOCATE;
}


void keyboard_intr_handler(){

    unsigned char scancode = inb(0x60);

    if ((scancode & 0b10000000) == 0b10000000){
        // released
        if (scancode == 0xAA) KEYBOARD_SHIFT_STATE = 0;
    }
    else{
        // pressed
        if (scancode == 0x2A) KEYBOARD_SHIFT_STATE = 1;
        else{
            BUFFER[BUFFER_LOCATE] = scancode;
            BUFFER_LOCATE = (BUFFER_LOCATE + 1) % BUFFER_SIZE;
        }
    }

    outb(0x20,0x20);
}


unsigned int keyboard_probe(void* data){
    register_interrupt_handler(33, keyboard_intr_handler_asm);
    return 1;
}
