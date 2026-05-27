#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include"src/config.h"
#include"src/cache.h"

int main(int argc, char* argv[]){
	srand(time(NULL));

	if (argc != 7){
		printf("Numero de argumentos incorreto. Utilize:\n");
		printf("./cache_simulator <nsets> <bsize> <assoc> <substituição> <flag_saida> arquivo_de_entrada\n");
		exit(EXIT_FAILURE);
	}
	int nsets = atoi(argv[1]);
	int bsize = atoi(argv[2]);
	int assoc = atoi(argv[3]);
	char substituion_method = argv[4];
	bool output_flag = atoi(argv[5]);
	char* input_file = argv[6];

	printf("nsets = %d\n", nsets);
	printf("bsize = %d\n", bsize);
	printf("assoc = %d\n", assoc);
	printf("subst = %s\n", substituion_method);
	printf("flagOut = %d\n", output_flag);
	printf("arquivo = %s\n", input_file);

    build_cache(nsets, bsize, assoc, substituion_method, output_flag, input_file);
    //Parameters: <nsets> <bsize> <assoc> <substituição> <flag_saida> arquivo_de_entrada


    return 0;
}