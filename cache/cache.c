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
    cache->valid_blocks = 0;

    //output type
    cache->output_flag = output_flag;

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
    cache_mapping(cache, c); // ----------CHANGE THIS

    //cache_substitution(); // ----------not necessary, since the substitution is handled inside cache_mapping
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

void cache_mapping(Cache *cache, uint32_t address){
    cache->accesses++;
    cache->global_time++;

    uint32_t index_mask = (1 << cache->config.index_bits) - 1;
    uint32_t index = (address >> cache->config.offset_bits) & index_mask;
    uint32_t tag = address >> (cache->config.offset_bits + cache->config.index_bits);

    int start_index = index * cache->config.assoc;
    bool hit = false;
    int empty_way = -1;

    for(int i = 0; i < cache->config.assoc; i++){
        CacheLine *current_line = &cache->lines[start_index + i];

        if(current_line->val && current_line->tag == tag){
            cache->hits++;
            hit = true;

            //on the LRU case:
            if(tolower(cache->config.substitution_method) == 'l'){
                current_line->timestamp = cache->global_time;
            }
            break;
        }

        if(!current_line->val && empty_way == -1){
            empty_way = i;
        }
    }

    if(!hit){
        cache->misses++;
        int target;

        if(empty_way != -1){
            cache->compulsory_misses++;
            cache->valid_blocks++;
            target = empty_way;
        } else{

            int total_cache_blocks = cache->config.nsets * cache->config.assoc;

            if(cache->valid_blocks >= total_cache_blocks){
                cache->capacity_misses++;
            } else{
                cache->conflict_misses++;
            }
            target = cache_substitution(cache, index);
        }
        CacheLine* target_line = &cache->lines[start_index + target];
        target_line->val = true;
        target_line->tag = tag;
        target_line->timestamp = cache->global_time;
    }

}