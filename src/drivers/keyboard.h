#pragma once

#define BUFFER_SIZE 16

#include "../libs/device.h"

struct device_desc KEYBOARD_DEV_DESC;
void* KEYBOARD_FUNC[];

void keyboard_intr_handler();

extern void keyboard_intr_handler_asm();

unsigned int keyboard_probe(void* data);
