#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<stdint.h> //import uint32_t (guarantee 32 bits of size)
#include"../src/config.h"

uint32_t catch_next_instruction_in_little_endian(FILE* benchmark){
    
    uint32_t op = 0u;

    fread(&op, sizeof(op), 1, benchmark);

    op |= getc(benchmark);          //0x000000AA
    op |= getc(benchmark) << 8;     //0x0000BBaa
    op |= getc(benchmark) << 16;     //0x00CCbbaa
    op |= getc(benchmark) << 24;     //0xDDccbbaa

    return op;
}

void process_cache_config(int nsets, int bsize, int assoc, char substituion_method, bool output_flag, char* input_file){
    
    int cache_val[nsets * assoc];
    int cache_tag[nsets * assoc];
    //criar uma estrutura de dados para armazenar os tags e os bits de validade

    double n_bits_offset = log((double) bsize);
    double n_bits_indice = log((double) nsets);

    double n_bits_tag = 32 - n_bits_offset - n_bits_indice;
    //descobre o numero de bits de cada parcela do address

    int accesses = 0;
    int miss_compulsorio = 0;
    int miss_capacidade = 0;
    int miss_conflito = 0;
    int hit = 0;
    //para todos os address do arquivo
    while(!EOF){
        
        FILE* benchmark = fopen(input_file, "r");

        bool full_cache = true;

        for(int i = 0; i < strlen(cache_val); ++i){
            if (cache_val[i] == 0){
                full_cache = false;
                return;
            } 
        }//verifica se todos os addresss estao ocupados

        uint32_t address = catch_next_instruction_in_big_endian(input_file);

        int tag = address >> ((int) (n_bits_offset + n_bits_indice));
        int indice = (address >> (int) n_bits_offset) && (pow(2, n_bits_indice - 1));
        //mascara que vai deixar apenas os bits do indice na variavel ?<address>?

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
                cache_val[indice] = 1;
                cache_tag[indice] = tag;
                
                //verifica se a  cache esta cheia (miss capacidade) ou nao (miss conflito)
                if(full_cache){
                    miss_capacidade++;
                }else{
                    miss_conflito++;
                }
            }
            
        //...

        
        float taxa_hit = hit/accesses;
        float taxa_miss = (miss_compulsorio+miss_capacidade+miss_conflito)/accesses;
        float taxa_compulsorio = miss_compulsorio/accesses;
        float taxa_capacidade = miss_capacidade/accesses;
        float taxa_conflito = miss_conflito/accesses;

        printf("%d, %f, %f, %f, %f, %f", accesses, taxa_hit, taxa_miss, taxa_compulsorio, taxa_capacidade, taxa_conflito);

    }
}

int method_random(int assoc){
    return (rand() % assoc);
}