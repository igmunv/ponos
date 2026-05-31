#pragma once

#include "../libs/program.h"


struct program* progman_programs_get();

unsigned int progman_program_count_get();

void progman_find_programs();

void progman_program_run(unsigned int program_index);
