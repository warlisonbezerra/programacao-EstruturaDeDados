#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char *arr[], int n) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            if (strcmp(arr[i], arr[i + 1]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char output_filename[256];

    // Gerar o nome do arquivo de saída
    snprintf(output_filename, sizeof(output_filename), "%s_ordenado.txt", input_filename);

    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

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

    bubbleSort(words, word_count);

    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < word_count; i++) {
        fprintf(output_file, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(output_file);

    printf("Saída: %s\n", output_filename);

    return 0;
}
