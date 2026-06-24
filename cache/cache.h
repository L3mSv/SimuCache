#ifndef CACHE_H

#define CACHE_H

#include <stdio.h>
#include <math.h>
#include "config/config.h"
#include "utils/utils.h"

void cache_init(Cache* cache, CacheConfig* cfg, bool output_flag);
void simulate(Cache* cache, char* benchmark);
void cache_destroy(Cache* cache);

#endif //CACHE_H