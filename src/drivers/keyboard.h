#pragma once

#include "../libs/device.h"

struct device_desc KEYBOARD_DEV_DESC;
void* KEYBOARD_FUNC[];

unsigned char KEYBOARD_SHIFT_STATE;

void keyboard_intr_handler();

extern void keyboard_intr_handler_asm();

unsigned int keyboard_probe(void* data);
