#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"../config/config.h"
#include"../cache/cache.h"

#ifndef UTILS_H

#define UTILS_H

uint32_t read_big_endian(FILE *fp);
uint32_t get_tag(uint32_t address, int offset_bits, int index_bits);
uint32_t get_index(uint32_t address, int offset_bits, int index_bits);

#endif //UTILS_H