#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include"config.h"

void process_cache_config(char* cache_simulator, int nsets, int bsize, int assoc, char substituion_method, bool output_flag, FILE* input_file){
    
    int cache_val[nsets * assoc];
    int cache_tag[nsets * assoc];
    //criar uma estrutura de dados para armazenar os tags e os bits de validade

    double n_bits_offset = log(bsize);
    double n_bits_indice = log(nsets);

    double n_bits_tag = 32 - n_bits_offset - n_bits_indice;
    //descobre o numero de bits de cada parcela do endereco
    
    int miss_compulsorio = 0;
    int hit = 0;
    int miss= 0;
    //para todos os enderecos do arquivo
    while(not EOF){
        
        FILE* benchmark = fopen(input_file, "r");
        int endereco = nsets * assoc;
        int tag = endereco >> ((int) (n_bits_offset + n_bits_indice));
        int indice = (endereco >> (int) n_bits_offset) && (pow(2, n_bits_indice - 1));
        //mascara que vai deixar apenas os bits do indice na variavel ?<endereco>?

        //para o mapeamento direto
        if(cache_val[indice] == 0){

            miss_compulsorio++;
            cache_val[indice] = 1;
            cache_tag[indice] = tag;
            //estas duas ultimas instrucoes representam o tratamento da falta
        }
        else
            if(cache_tag[indice] == tag)
                hit++;
            else{
                miss++;
                    //conflito ou capacidade?
                    cache_val[indice] = 1;
                    cache_tag[indice] = tag;
            }
            
        //...
    }
}