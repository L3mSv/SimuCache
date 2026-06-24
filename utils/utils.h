#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "config/config.h"


#ifndef UTILS_H

#define UTILS_H

uint32_t read_big_endian(FILE *fp);
void output_print_normalize(Cache* cache);

#endif //UTILS_H