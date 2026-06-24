#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"../config/config.h"
#include"../cache/cache.h"
#include"../utils/utils.h"

void cache_init(Cache* cache, CacheConfig* cfg, bool output_flag){
    
    //copy cache config
    cache->config = *cfg;

    //incialize parameters
    cache->hits = 0;
    cache->misses = 0;
    cache->accesses = 0;
    cache->compulsory_misses = 0;
    cache->capacity_misses = 0;
    cache->conflict_misses = 0;
    cache->valid_blocks = 0;

    //output type
    cache->output_flag = output_flag;

    //copy cache lines
    cache->lines = calloc(
        cfg->nsets * cfg->assoc,
        sizeof(CacheLine)
    );
}

void simulate(Cache* cache, char* file)
{
    char path[256];
    snprintf(path, sizeof(path), "benchmarks/%s", file);

    FILE* benchmark = fopen(path, "rb");

    if (!benchmark) {
        perror("Error opening benchmark");
        return;
    }

    uint32_t addr;

    while ((addr = read_big_endian(benchmark)) != UINT32_MAX)
    {
        cache_mapping(cache, addr);
    }

    if (cache->output_flag)
        output_print_normalize(cache);
    else
        printf("CUSTOM OUTPUT\n");

    fclose(benchmark);
}

void cache_destroy(Cache* cache){
    free(cache->lines);
    free(cache);
}
