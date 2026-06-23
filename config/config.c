#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdint.h> //import uint32_t (guarantee 32 bits of size)
#include "config/config.h"

void create_cache_config(CacheConfig* config, int nsets, int bsize, int assoc, char substitution_method){

	config->nsets = nsets;
	config->bsize = bsize;
	config->assoc = assoc;

	config->substitution_method = substitution_method;

	config->offset_bits = (int) log2(config->bsize);
	config->index_bits = (int) log2(config->nsets);
	config->tag_bits = 32 - config->offset_bits - config->index_bits;

}

void cache_mapping(Cache* cache, uint32_t address){
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

int cache_substitution(Cache* cache, uint32_t set_index){
    int assoc = cache->config.assoc;

    char method = tolower(cache->config.substitution_method);

    if(method == 'r'){
        return (rand() % assoc);
    }

    //both of the methods LRU aNd FIFO are controlled by this logic:

    int victim = 0;

    uint32_t oldest_time = cache->lines[set_index * assoc].timestamp;

    for (int i = 1; i < assoc; i++) {
        uint32_t current_time = cache->lines[set_index * assoc + i].timestamp;
        
        if (current_time < oldest_time) {
            oldest_time = current_time;
            victim = i;
        }
    }
    return victim;
}
