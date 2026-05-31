#pragma once


#include "../kernel/idt.h"
#include "../kernel/device_manager.h"
#include "../kernel/driver_manager.h"
#include "../kernel/program_manager.h"


void _print(unsigned char* text, unsigned char size);
void _clear();
void _print_symbol(unsigned char symbol, unsigned char frg_color, unsigned char bkg_color);
unsigned char* _get_keyboard_buffer();
unsigned char* _get_keyboard_buffer_loc();
