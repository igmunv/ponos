#include "program_manager.h"

#define FINAL_SECTOR 512
#define MAX_PROGRAM_COUNT 256

#include "../libs/memory.h"
#include "../libs/string.h"


struct program PROGRAMS[MAX_PROGRAM_COUNT] = {};
unsigned int PROGRAM_COUNT = 0;


void progman_program_add(unsigned char* name, unsigned int sector){
    struct program new_program;
    memcpy(name, new_program.name, 16);
    new_program.sector = sector;
    PROGRAMS[PROGRAM_COUNT] = new_program;
    PROGRAM_COUNT++;
}


struct program* progman_programs_get(){
    return &PROGRAMS;
}

unsigned int progman_program_count_get(){
    return PROGRAM_COUNT;
}


void progman_find_programs(){

    for (int sector = 0; sector < FINAL_SECTOR; sector++){

        unsigned char buffer[512] = {};
        _ata_read_sector(buffer, sector, 1);

        unsigned char header[16] = {};
        unsigned char name[16] = {};

        memcpy(buffer, header, 16);
        memcpy(buffer+16, name, 16);

        _print(header, 16);
        _print("\n", 1);
        _print(name, 16);

        if (str_equal(header, "###iamprogram###", 16) == 1){
            _print("\nEQUAL!!!\n", 10);
            progman_program_add(name, sector);
        }

    }

}


