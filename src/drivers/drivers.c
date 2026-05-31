#include "keyboard.h"


void register_drivers(){
    drvman_driver_reg(KEYBOARD_DEV_DESC, keyboard_probe, KEYBOARD_FUNC);
}
