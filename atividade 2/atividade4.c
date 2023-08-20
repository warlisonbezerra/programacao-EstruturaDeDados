#include <stdio.h>
#include <locale.h>

/*função*/
int conta_int_array(int arr[], int n, int busca) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == busca) {
            contador++;
        }
    }
    return contador;
}

/*programa principal*/
int main() {
    setlocale(LC_ALL,"Portuguese");
    int arr[] = {5, 7, 9, 6, 7, 11, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int busca = 7;
    printf("Saída: %d", conta_int_array(arr, n, busca));
    return 0;
}
