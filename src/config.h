#include<stdbool.h>
#include<stdio.h>
#include<stdint.h>

#ifndef CONFIG_H

#define CONFIG_H

void process_cache_config(int nsets, int bsize, int assoc, char substituion_method, bool output_flag, char* input_file);
uint32_t catch_next_instruction_in_little_endian(FILE* benchmark);
int method_random(int assoc);

#endif //CONFIG_H 