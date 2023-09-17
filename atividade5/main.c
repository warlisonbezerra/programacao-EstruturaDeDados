#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"
#include "bubble_sort.c"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arq_palavras.txt", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char output_filename[256];

    // Gerar o nome do arquivo de saída
    snprintf(output_filename, sizeof(output_filename), "%s_ordenado.txt", input_filename);

    // Implemente o código para ler o arquivo de entrada, ordenar as palavras e criar o arquivo de saída aqui.
    // Abrir o arquivo de entrada
    FILE *input_file = fopen("C:\\Users\\warli\\Desktop\\AtividadeProgramacaoFaculdade\\programacao-EstruturaDeDados\\atividade5\\arq_palavras.txt", "r");
    if (!input_file) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Ler as palavras do arquivo de entrada e armazená-las em um array
    int max_words = 1000; // Defina o número máximo de palavras esperado no arquivo
    char *words[max_words];
    int word_count = 0;

    char line[256];
    while (fgets(line, sizeof(line), input_file)) {
        line[strcspn(line, "\n")] = '\0'; // Remover a quebra de linha
        words[word_count] = strdup(line);
        word_count++;
    }

    fclose(input_file);

    // Chamar a função bubbleSort para ordenar as palavras
    bubbleSort(words, word_count);

    // Abrir o arquivo de saída
    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    // Escrever as palavras ordenadas no arquivo de saída
    for (int i = 0; i < word_count; i++) {
        fprintf(output_file, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(output_file);

    printf("Saída: %s\n", output_filename);

    return 0;
}