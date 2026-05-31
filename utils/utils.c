#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<../utils/utils.h>

uint32_t read_big_endian(FILE* benchmark){
    
    uint32_t op = 0u;

    fread(&op, sizeof(op), 1, benchmark);

    op |= getc(benchmark);          //0x000000AA
    op |= getc(benchmark) << 8;     //0x0000BBaa
    op |= getc(benchmark) << 16;     //0x00CCbbaa
    op |= getc(benchmark) << 24;     //0xDDccbbaa

    return op;
}

void output_print_normalize(Cache* cache){

    float hit_ratio = cache->hits / cache->accesses;
    float miss_ratio = cache->misses / cache->accesses;
    float compulsory_ratio = cache->compulsory_misses / cache->misses;
    float capacity_ratio = cache->capacity_misses / cache->misses;
    float conflict_misses = cache->conflict_misses / cache->misses;

    printf("%d, %f, %f, %f, %f, %f", cache->accesses, hit_ratio, miss_ratio, compulsory_ratio, capacity_ratio, conflict_ratio);
}

