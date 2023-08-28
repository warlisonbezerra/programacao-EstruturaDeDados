#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    char filename[] = "dados.csv"; // Nome do arquivo CSV
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Usamos a função strtok para separar os valores da linha usando vírgulas como delimitadores
        char *token = strtok(line, ",");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}
