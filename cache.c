#include<stdio.h>
#include<math.h>
#include"config.h"
#include"cache.h"

void build_cache(char* cache_simulator, int nsets, int bsize, int assoc, char substituion_method, bool output_flag, FILE* input_file){

    process_cache_config(cache_simulator, nsets, bsize, assoc, substituion_method,  output_flag, input_file);
}


