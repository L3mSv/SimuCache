#include<stdio.h>
#include<math.h>
#include"../src/config.h"
#include"../src/cache.h"

void build_cache(int nsets, int bsize, int assoc, char substituion_method, bool output_flag, char* input_file){

    process_cache_config(nsets, bsize, assoc, substituion_method,  output_flag, input_file);
}
