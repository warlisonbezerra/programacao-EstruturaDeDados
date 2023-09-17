#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arq_palavras.txt\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];


    char full_path[256]; 
    snprintf(full_path, sizeof(full_path), "C:\\Users\\warli\\Desktop\\AtividadeProgramacaoFaculdade\\programacao-EstruturaDeDados\\atividade5\\arq_palavras.txt%s", input_filename);

    // Abra o arquivo de entrada
    FILE *input_file = fopen(full_path, "r");
    if (!input_file) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Restante do código
    // ...

    return 0;
}
