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

uint32_t get_tag(uint32_t address, int offset_bits, int index_bits);
uint32_t get_index(uint32_t address, int offset_bits, int index_bits);