#include<stdio.h>
#include<math.h>
#include"../config/config.h"
#include"../utils/utils.h"

#ifndef CACHE_H

#define CACHE_H

void cache_init(Cache* cache, CacheConfig cfg);
int cache_access(Cache* cache, uint32_t address);
void cache_destroy(Cache* cache);

#endif //CACHE_H