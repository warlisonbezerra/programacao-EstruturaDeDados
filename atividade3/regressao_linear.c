#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto {
    double x;
    double y;
} Ponto;

Ponto* lerPontos(char* nomeArquivo, int* numPontos) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return NULL;
    }

    Ponto* pontos = NULL;
    double x, y;
    *numPontos = 0;

    while (fscanf(arquivo, "%lf,%lf", &x, &y) == 2) {
        pontos = realloc(pontos, (*numPontos + 1) * sizeof(Ponto));
        pontos[*numPontos].x = x;
        pontos[*numPontos].y = y;
        (*numPontos)++;
    }

    fclose(arquivo);
    return pontos;
}

void calcularRegressaoLinear(Ponto* pontos, int numPontos) {
    double somaX = 0, somaY = 0, somaXY = 0, somaXQuadrado = 0;
    for (int i = 0; i < numPontos; i++) {
        somaX += pontos[i].x;
        somaY += pontos[i].y;
        somaXY += pontos[i].x * pontos[i].y;
        somaXQuadrado += pontos[i].x * pontos[i].x;
    }

    double mediaX = somaX / numPontos;
    double mediaY = somaY / numPontos;

    double m = (numPontos * somaXY - somaX * somaY) / (numPontos * somaXQuadrado - somaX * somaX);
    double b = mediaY - m * mediaX;

    printf("A equação da linha de regressão linear é: y = %.2lf * x + %.2lf\n", m, b);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Uso: %s <nome do arquivo>\n", argv[0]);
        return 1;
    }

    int numPontos;
    Ponto* pontos = lerPontos(argv[1], &numPontos);

    if (pontos != NULL) {
        calcularRegressaoLinear(pontos, numPontos);
        free(pontos);
    }

    return 0;
}
