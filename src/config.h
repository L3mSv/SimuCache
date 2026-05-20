#include<stdbool.h>
#include<stdio.h>

#ifndef CONFIG_H

#define CONFIG_H

void process_cache_config(char* cache_simulator, int nsets, int bsize, int assoc, char substituion_method, bool output_flag, FILE* input_file);

#endif //CONFIG_H 