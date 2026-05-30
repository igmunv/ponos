#pragma once

extern void io_wait();

extern void outb(unsigned short dest, unsigned char value);
extern void outw(unsigned short dest, unsigned short value);

extern unsigned char inb(unsigned short dest);
extern unsigned short inw(unsigned short dest);
