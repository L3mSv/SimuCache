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
		printf("Numero de argumentos incorreto. Utilize:\n");
		printf("./cache_simulator <nsets> <bsize> <assoc> <substituição> <flag_saida> arquivo_de_entrada\n");
		exit(EXIT_FAILURE);
	}

	//================== CONFIG (PART)
	CacheConfig* config;

	create_cache_config(config, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), argv[4][0]);

	//================== CACHE (PART)
	Cache* cache;

	cache_init(cache, config, atoi(argv[5]));

	simulate(cache, argv[6]);

	cache_destroy(cache);

    return 0;
}