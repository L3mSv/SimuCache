#ifndef CONFIG_H

#define CONFIG_H

#include<stdbool.h>
#include<stdio.h>
#include<stdint.h>
#include"../cache/cache.h"
#include"../utils/utils.h"

typedef struct{
    int nsets;
    int bsize;
    int assoc;

    char substitution_method;

    int offset_bits;
    int index_bits;
    int tag_bits;

}CacheConfig;

typedef struct{
    bool val;
    uint32_t tag;
    uint32_t timestamp;
}CacheLine;

typedef struct{
    CacheLine* lines;
    CacheConfig config;

    bool output_flag;
    
    int accesses;
    int hits;
    int misses;
    int compulsory_misses;
    int capacity_misses;
    int conflict_misses;

    uint32_t global_time;
    int valid_blocks;
}Cache;

//void process_cache_config(int nsets, int bsize, int assoc, char substituion_method, bool output_flag, char* input_file);
//int method_random(int assoc);

CacheConfig create_cache_config(int nsets, int bsize, int assoc, char substituion_method);
void cache_mapping(Cache *cache, uint32_t address);
int cache_substitution(Cache* cache, uint32_t set_index);


#endif //CONFIG_H 