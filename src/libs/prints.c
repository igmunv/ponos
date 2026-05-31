# include "prints.h"

#include "../api/kapi.h"


unsigned char nibble_to_hex(unsigned char nibble){
    switch(nibble){
        case 0x00: return '0';
        case 0x01: return '1';
        case 0x02: return '2';
        case 0x03: return '3';
        case 0x04: return '4';
        case 0x05: return '5';
        case 0x06: return '6';
        case 0x07: return '7';
        case 0x08: return '8';
        case 0x09: return '9';
        case 0x0a: return 'a';
        case 0x0b: return 'b';
        case 0x0c: return 'c';
        case 0x0d: return 'd';
        case 0x0e: return 'e';
        case 0x0f: return 'f';
    }
}


void byte_to_hex(unsigned char byte, unsigned char* result){
    unsigned char nibble1 = (byte >> 4) & 0x0f;
    unsigned char nibble2 = byte & 0x0f;

    result[0] = nibble_to_hex(nibble1);
    result[1] = nibble_to_hex(nibble2);
    result[2] = '\0';

}


void print_bytes(unsigned char* bytes, unsigned short size){

    for (int i = 0; i < size; i++){
        unsigned char byte = bytes[i];
        unsigned char hex[3];
        byte_to_hex(byte, hex);
        _print("0x",2);
        _print(hex,2);
        _print(" ",1);
    }

}
