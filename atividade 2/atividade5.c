#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*função*/
int *multiplica_array(int arr1[], int arr2[], int n) {
    int *resultado = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        resultado[i] = arr1[i] * arr2[i];
    }
    return resultado;
}

/*programa principal*/
int main() {
    setlocale(LC_ALL,"Portuguese");
    int arr1[] = {5, 7, 9, 6};
    int arr2[] = {5, 7, 9, 6};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int *resultado = multiplica_array(arr1, arr2, n);
    printf("Saída: [");
    for (int i = 0; i < n; i++) {
        printf("%d", resultado[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]");
    free(resultado);
    return 0;
}
