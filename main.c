#include<stdio.h>
#include<math.h>
#include"src/config.h"
#include"src/cache.h"

int main(int argc, char* argv[]){

    build_cache(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
    //Parameters: cache_simulator <nsets> <bsize> <assoc> <substituição> <flag_saida> arquivo_de_entrada

    return 0;
}