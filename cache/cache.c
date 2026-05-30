#include<stdio.h>
#include<math.h>
#include"../config/config.h"
#include"../cache/cache.h"
#include"../utils/utils.h"

void cache_init(Cache* cache, CacheConfig cfg){

}

int cache_access(Cache* cache, uint32_t address);

void cache_destroy(Cache* cache){
    free(cache->lines);
}