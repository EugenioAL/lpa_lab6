#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"

int lerFile(char *file, struct zip_file_hdr *tmp){
    FILE *file_hdr = fopen(file, "rb");
    int cont = 1;
    if(file_hdr == NULL){
        printf("Arquivo nao existe!\n");
        return 4;
    }
    tmp = malloc(sizeof(struct zip_file_hdr));
    
    while(!feof(file_hdr)){
        fread(tmp, sizeof(struct zip_file_hdr), 1, file_hdr);
        if(tmp -> signature != 0x04034b50){
            printf("Erro: Nao e um cabecalho\n");
            return 1;
        }

        char *nome = (char*)malloc((tmp -> name_length *sizeof(char) +1));
        fread(nome,tmp -> name_length *sizeof(char) + 1,1,file_hdr);
        nome[tmp -> name_length * sizeof(char)] = '\0';
        printf("Arquivo %d ..\n",cont);
        printf("--> Nome do Arquivo: %s\n",nome);
        printf("--> Tamanho Compactado: %d\n",tmp -> compressed_size);
        printf("--> Tamanho Descompactado: %d\n",tmp -> uncompressed_size);
        cont ++;
        free(nome);
        fseek(file_hdr,tmp -> extra_field_length + tmp -> compressed_size - 1, SEEK_CUR);
    
    }
    free(tmp);
    return 0;

}