#include "tools.h"


void print_char(unsigned char symbol, unsigned char offset){
    unsigned short value = (unsigned short)((0b00001111 << 8)|(symbol));
    unsigned short* address_symbol = (unsigned short*)0xB8000+(offset*2);
    *address_symbol = value;
}
