#include<stdbool.h>
#include<stdio.h>
#include<stdint.h>
#include"../cache/cache.h"
#include"../utils/utils.h"

typedef struct{
    int nsets;
    int bsize;
    int assoc;

    char substituiton_method;

    int offset_bits;
    int index_bits;
    int tag_bits;

}CacheConfig;

typedef struct{
    bool val;
    uint32_t tag;

}CacheLine;

typedef struct{
    CacheLine* lines;
    CacheConfig config;

    bool output_flag;
    char* input_file;
    
    int accesses;
    int hits;
    int misses;
}Cache;



#ifndef CONFIG_H

#define CONFIG_H

void process_cache_config(int nsets, int bsize, int assoc, char substituion_method, bool output_flag, char* input_file);
uint32_t catch_next_instruction_in_little_endian(FILE* benchmark);
int method_random(int assoc);

CacheConfig create_cache_config(int nsets, int bsize, int assoc, char substituion_method);

#endif //CONFIG_H 