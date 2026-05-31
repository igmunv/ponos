#include "keyboard.h"
#include "vga_tm.h"
#include "ata.h"

void register_drivers(){
    drvman_driver_reg(KEYBOARD_DEV_DESC, keyboard_probe, KEYBOARD_FUNC);
    drvman_driver_reg(VGA_TM_DEV_DESC, vga_tm_probe, VGA_TM_FUNC);
    drvman_driver_reg(ATA_DEV_DESC, ata_probe, ATA_FUNC);
}
