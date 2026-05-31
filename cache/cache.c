#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"../config/config.h"
#include"../cache/cache.h"
#include"../utils/utils.h"

void cache_init(Cache* cache, CacheConfig cfg, bool output_flag){
    
    //incialize parameters
    cache->hits = 0;
    cache->misses = 0;
    cache->accesses = 0;
    cache->compulsory_misses = 0;
    cache->capacity_misses = 0;
    cache->conflict_misses = 0;

    //output type
    cache->output_flag = output_flag

    //creating cache lines
    cache->lines = calloc(
        cfg.nsets * cfg assoc,
        sizeof(CacheLine)
    );
}

void simulate(Cache* cache, FILE* benchmark){

    uint32_t c;
    while ((c = fgetc(benchmark)) != EOF)
    {
    cache_mapping(); // ----------MAKE THIS

    cache_substituion(); // ----------MAKE THIS
    }
    if(feof(stream))
    {
        //verifying output flag
        if(cache->output_flag == 1){
            output_print_normalize(cache);
        }else{
            printf("CUSTOM OUTPUT");
        }
    }
    else
    {
        printf("\nERROR: Can't read file");
        exit(EXIT_FAILURE);
    }
}

void cache_destroy(Cache* cache){
    free(cache->lines);
}