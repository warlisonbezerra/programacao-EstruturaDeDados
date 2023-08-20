#include <stdio.h>
#include <locale.h>

int soma_array(int arr[], int n) {
    setlocale(LC_ALL,"Portuguese");
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += arr[i];
    }
    return soma;
}

int main() {
    int arr[] = {9, 24, 13, 400, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("A soma dos elementos do array é %d", soma_array(arr, n));
    return 0;
}