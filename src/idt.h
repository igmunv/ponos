#pragma once

#define ICW_1 0x11

#define PIC_1_CTRL 0x20
#define PIC_2_CTRL 0xA0

#define PIC_1_DATA 0x21
#define PIC_2_DATA 0xA1

#define IRQ_0 0x20
#define IRQ_8 0x28


typedef void (*inter_handler)();


struct InterruptDescriptor {
   unsigned short offset_1;        // offset bits 0..15
   unsigned short selector;        // a code segment selector in GDT or LDT
   unsigned char zero;            // unused, set to 0
   unsigned char type_attributes; // gate type, dpl, and p fields
   unsigned short offset_2;        // offset bits 16..31
} __attribute__((packed));


struct IDTr {
	unsigned short limit;
	unsigned int base;
} __attribute__((packed));


struct InterruptDescriptor IDT_table[256];
struct IDTr idtr;


void interrupt_init();

void IRQ_mask();

void PIC_remap();

void PIC_sendEOI();

void register_interrupt_handler(unsigned char vector, inter_handler hand_address);
