#include "vga_tm.h"

#include "../libs/asm.h"

struct device_desc VGA_TM_DEV_DESC = {LEGACY, LEG_VGA_TM, 0};


void vga_tm_print_text(unsigned char* text, unsigned short size);
void vga_tm_clear();
void vga_tm_print_symb(unsigned char symbol, unsigned char frg_color, unsigned char bkg_color);

void* VGA_TM_FUNC[] = {
    vga_tm_print_text,
    vga_tm_clear,
    vga_tm_print_symb
};


unsigned char pos_x = 0;
unsigned char pos_y = 0;

unsigned char max_pos_x = 79;
unsigned char max_pos_y = 25;

unsigned char default_frg_color = 15;
unsigned char default_bkg_color = 0;


void pos_reset(){
    pos_x = 0;
    pos_y = 0;
}

void vga_tm_cursor_update(){
    unsigned short pos = pos_y * 80 + pos_x;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (unsigned char) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (unsigned char) ((pos >> 8) & 0xFF));
}


void vga_tm_clear(){
    unsigned short value = (unsigned short)0b0000111100000000;
    for (int i = 0; i < 80*25; i++){
        unsigned short* address = (unsigned short*)0xB8000+i;
        *address = value;
    }
    pos_reset();
    vga_tm_cursor_update();
}


void add_pos_y(){
    pos_x = 0;
    if ((pos_y + 1) > max_pos_y)
        pos_y = 0;
    else
        pos_y++;
}

void add_pos_x(){
    if ((pos_x + 1) > max_pos_x)
        add_pos_y();
    else
        pos_x++;
}


void vga_tm_enable_cursor(unsigned char cursor_start, unsigned char cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);

	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}


void vga_tm_disable_cursor()
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}


void vga_tm_print_symb(unsigned char symbol, unsigned char frg_color, unsigned char bkg_color){

    if (symbol == '\n'){
        add_pos_y();
    }
    else{
        unsigned short value = (unsigned short)(((unsigned char)((bkg_color << 4) | frg_color) << 8)|(symbol));
        unsigned short* address = (unsigned short*)0xB8000+((pos_y*80) + pos_x);
        *address = value;
        add_pos_x();
    }
    vga_tm_cursor_update();
}


void vga_tm_print_text(unsigned char* text, unsigned short size){

    for (int i = 0; i < size; i++){
        unsigned char symbol = text[i];
        if (symbol == '\0') break;
        vga_tm_print_symb(symbol, default_frg_color, default_bkg_color);
    }

}


unsigned int vga_tm_probe(void* data){
    vga_tm_clear();
    return 1;
}
