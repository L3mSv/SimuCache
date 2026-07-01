#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "config/config.h"
#include "cache/cache.h"
#include "utils/utils.h"

int main(int argc, char* argv[]){
	srand(time(NULL));

	//=================== CALL (PART)
	if (argc != 7){
		printf("Incorrect number of arguments. Use:\n");
		printf("./cache_simulator <nsets> <bsize> <assoc> <substituição> <flag_saida> arquivo_de_entrada\n");
		exit(EXIT_FAILURE);
	}

	//================== POWER OF TWO TEST (PART)
	int nsets = atoi(argv[1]);
	int bsize = atoi(argv[2]);
	int assoc = atoi(argv[3]);

	if ((nsets & (nsets - 1)) != 0 || (bsize & (bsize - 1)) != 0 || (assoc & (assoc - 1)) != 0){
		printf("Error: nsets, bsize, and assoc must be powers of two.\n");
		exit(EXIT_FAILURE);
	}

	//================== CONFIG (PART)
	CacheConfig* config = (CacheConfig*) malloc(sizeof(CacheConfig));

	create_cache_config(config, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), argv[4][0]);

	//================== CACHE (PART)
	Cache* cache = (Cache*) malloc(sizeof(Cache));

	cache_init(cache, config, atoi(argv[5]));

	simulate(cache, argv[6]);

	cache_destroy(cache);

    return 0;
}