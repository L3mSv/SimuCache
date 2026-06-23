#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdint.h> //import uint32_t (guarantee 32 bits of size)
#include "config/config.h"

void create_cache_config(CacheConfig *config, int nsets, int bsize, int assoc, char substitution_method){

	config->nsets = nsets;
	config->bsize = bsize;
	config->assoc = assoc;

	config->substitution_method = substitution_method;

	config->offset_bits = (int) log2(config->bsize);
	config->index_bits = (int) log2(config.nsets);
	config->tag_bits = 32 - config->offset_bits - config->index_bits;

}

void cache_mapping(); 

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
