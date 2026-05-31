#include "idt.h"

#include "../libs/asm.h"


void interrupt_disable(){
    asm("cli");
}


void interrupt_enable(){
    asm("sti");
}


void PIC_remap(){

    interrupt_disable();

    outb(PIC_1_CTRL, ICW_1); io_wait();
    outb(PIC_2_CTRL, ICW_1); io_wait();

    outb(PIC_1_DATA, IRQ_0); io_wait();
    outb(PIC_2_DATA, IRQ_8); io_wait();

    outb(PIC_1_DATA, 0x04); io_wait();
    outb(PIC_2_DATA, 0x02); io_wait();

    outb(PIC_1_DATA, 0x01); io_wait();
    outb(PIC_2_DATA, 0x01); io_wait();

    outb(PIC_1_DATA, 0b11111101); io_wait();
    outb(PIC_2_DATA, 0xff); io_wait();

    interrupt_enable();

}


void register_interrupt_handler(unsigned char vector, inter_handler handler){

    interrupt_disable();

    unsigned int hand_address = (unsigned int) handler;

    IDT_table[vector].offset_1        = (unsigned short)(hand_address & 0xFFFF);
    IDT_table[vector].selector      = (unsigned short)0x08;
    IDT_table[vector].zero     = (unsigned char)0;
    IDT_table[vector].type_attributes       = (unsigned char)(0x80 | 0x0E);
    IDT_table[vector].offset_2       = (unsigned short)(hand_address >> 16);

    idt_load();

    interrupt_enable();

}


void idt_load() {
    int IDT_row_count = sizeof(IDT_table) / sizeof(IDT_table[0]);
    idtr.base = (unsigned int)(&IDT_table[0]);
    idtr.limit = (sizeof(struct InterruptDescriptor) * IDT_row_count) - 1;
    __asm__ volatile ("lidt %0" : : "m"(idtr));
}

void interrupt_init(){
    PIC_remap();
}
