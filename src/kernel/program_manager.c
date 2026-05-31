#include "program_manager.h"

#define FINAL_SECTOR 1024
#define MAX_PROGRAM_COUNT 256

#include "../libs/memory.h"
#include "../libs/string.h"


struct program PROGRAMS[MAX_PROGRAM_COUNT] = {};
unsigned int PROGRAM_COUNT = 0;


void progman_program_add(unsigned char* name, unsigned int start_sector, unsigned int end_sector){
    struct program new_program;
    memcpy(name, new_program.name, 16);
    new_program.start_sector = start_sector;
    new_program.end_sector = end_sector;
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

    unsigned int start_sector = 0;
    unsigned char prog_name[16] = {};

    for (int sector = 0; sector < FINAL_SECTOR; sector++){

        unsigned char buffer[512] = {};
        _ata_read_sector(buffer, sector, 1);

            unsigned char header[16] = {};
            unsigned char name[16] = {};

            memcpy(buffer, header, 16);
            memcpy(buffer+16, name, 16);

            if (str_equal(header, "###iamprogram###", 16) == 1){
                memcpy(name, prog_name, 16);
                start_sector = sector;
            }


            for (int i = 0; i < 512-15; i++){
                unsigned char potential_trailer[16] = {
                    buffer[i],
                    buffer[i+1],
                    buffer[i+2],
                    buffer[i+3],
                    buffer[i+4],
                    buffer[i+5],
                    buffer[i+6],
                    buffer[i+7],
                    buffer[i+8],
                    buffer[i+9],
                    buffer[i+10],
                    buffer[i+11],
                    buffer[i+12],
                    buffer[i+13],
                    buffer[i+14],
                    buffer[i+15]
                };

                if (str_equal(potential_trailer, "###endprogram###", 16) == 1){
                    progman_program_add(prog_name, start_sector, sector);
                    start_sector = 0;
                    break;
                }
            }
    }
}


void progman_program_run(unsigned int program_index){
    _print("\nstart move to ram\n", 50);
    struct program* prog = &PROGRAMS[program_index];
    _print("\nstart move to ram\n", 50);
    for (int sector = prog->start_sector, i = 0; sector <= prog->end_sector; sector++, i++){
        unsigned char buffer[512] = {};
        _ata_read_sector(buffer, sector, 1);

        memcpy(buffer,(unsigned char*)(0x50000+(512*i)),512);

    }
    _print("\nokay\n", 50);


    int (*_start)() = (int (*)())(0x50020);

    _print("\nnow call _start()\n", 50);
    _start();
    _print("\nexit from _start()\n", 50);

}


