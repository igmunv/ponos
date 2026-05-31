#include "colorama.h"

volatile unsigned char header[16] __attribute__((section(".header"))) = "###iamprogram###";
volatile unsigned char name[16] __attribute__((section(".name"))) = "colorama";


int _start() __attribute__((section(".text.start")));
int _start(){

    for (int i = 0; i <= 9999999999; i++){
        asm("hlt");
    }

}
