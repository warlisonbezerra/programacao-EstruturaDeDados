#include <stdio.h>
#include <string.h>
#include <locale.h>

/*função*/
int busca_string(char *arr[], int n, char *busca) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], busca) == 0) {
            return 1;
        }
    }
    return 0;
}
/*programa principal*/
int main() {
    setlocale(LC_ALL,"Portuguese");
    char *arr[] = {"texto", "J", "EDA"};
    int n = sizeof(arr) / sizeof(arr[0]);
    char *busca = "EDA";
    printf("Saída: %d", busca_string(arr, n, busca));
    return 0;
}
