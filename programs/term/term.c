#include "term.h"

volatile unsigned char header[16] __attribute__((section(".header"))) = "###iamprogram###";
volatile unsigned char trailer[16] __attribute__((section(".trailer"))) = "###endprogram###";
volatile unsigned char name[16] __attribute__((section(".name"))) = "term";


int _start() __attribute__((section(".text.start")));
int _start(){

}
