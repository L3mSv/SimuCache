#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <utils/utils.h>

uint32_t read_big_endian(FILE *benchmark)
{
    int b0 = getc(benchmark);
    int b1 = getc(benchmark);
    int b2 = getc(benchmark);
    int b3 = getc(benchmark);

    if (b0 == EOF || b1 == EOF || b2 == EOF || b3 == EOF)
        return UINT32_MAX;

    return ((uint32_t)b0 << 24)|((uint32_t)b1 << 16)|((uint32_t)b2 << 8)|(uint32_t)b3;
}

void output_print_normalize(Cache* cache){

    float hit_ratio = (float) cache->hits / cache->accesses;
    float miss_ratio = (float) cache->misses / cache->accesses;
    float compulsory_ratio = (float) cache->compulsory_misses / cache->misses;
    float capacity_ratio = (float) cache->capacity_misses / cache->misses;
    float conflict_misses = (float) cache->conflict_misses / cache->misses;
    float conflict_ratio = (float) cache->conflict_misses / cache->misses;

    printf("%d, %.4f, %.4f, %.4f, %.4f, %.4f", cache->accesses, hit_ratio, miss_ratio, compulsory_ratio, capacity_ratio, conflict_ratio);
}

