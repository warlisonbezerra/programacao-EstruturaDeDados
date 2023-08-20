#include <stdio.h>
#include <locale.h>

/*variáveis*/
struct MinMax {
    int min;
    int max;
};

/*função com o cálculo das variáveis*/
struct MinMax min_max(int arr[], int n) {
    struct MinMax result; 
    result.min = arr[0];
    result.max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < result.min) {
            result.min = arr[i];
        }
        if (arr[i] > result.max) {
            result.max = arr[i];
        }
    }
    return result;
}

/*programa principal com output*/
int main() {
    setlocale(LC_ALL,"Portuguese");
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct MinMax result = min_max(arr, n);
    printf("O menor elemento do array é %d e o maior é %d", result.min, result.max);
    return 0;
}
