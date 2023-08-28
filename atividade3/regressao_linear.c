#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os pontos (x, y)
struct Point {
    double x;
    double y;
};

// Função para calcular os coeficientes de regressão linear
void linearRegression(struct Point *data, int n, double *slope, double *intercept) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    
    for (int i = 0; i < n; i++) {
        sumX += data[i].x;
        sumY += data[i].y;
        sumXY += data[i].x * data[i].y;
        sumX2 += data[i].x * data[i].x;
    }
    
    double meanX = sumX / n;
    double meanY = sumY / n;
    
    *slope = (sumXY - n * meanX * meanY) / (sumX2 - n * meanX * meanX);
    *intercept = meanY - (*slope) * meanX;
}

int main() {
    FILE *file = fopen("dadosProjeto.csv", "r");
    if (file == NULL) {
        printf("Nao da para abrir.\n");
        return 1;
    }

    // Contar quantas linhas (pontos) estão no arquivo
    int numPoints = 0;
    char ch;
    while (!feof(file)) {
        ch = fgetc(file);
        if (ch == '\n') {
            numPoints++;
        }
    }
    fseek(file, 0, SEEK_SET);  // Voltar ao início do arquivo
    
    // Ler os pontos do arquivo
    struct Point *data = (struct Point *)malloc(numPoints * sizeof(struct Point));
    for (int i = 0; i < numPoints; i++) {
        fscanf(file, "%lf,%lf", &data[i].x, &data[i].y);
    }
    fclose(file);
    
    // Calcular regressão linear
    double slope, intercept;
    linearRegression(data, numPoints, &slope, &intercept);
    
    printf("Coeficiente angular (slope): %lf\n", slope);
    printf("Coeficiente linear (intercept): %lf\n", intercept);

    free(data);
    return 0;
}
