#include<stdio.h>
#include<math.h>

#ifndef CACHE_H

#define CACHE_H

void build_cache(char* cache_simulator, int nsets, int bsize, int assoc, char substituion_method, bool output_flag, FILE* input_file);

#endif //CACHE_H