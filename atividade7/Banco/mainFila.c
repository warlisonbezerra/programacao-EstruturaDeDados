#include <stdio.h>
#include "fila.h"
#include "fila.c"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    Fila* fila = criar_fila();

    Cliente cliente1 = {1, "Cliente 1"}; //está pegando o valor da mémoria e não a variável, por que?
    Cliente cliente2 = {2, "Cliente 2"};
    Cliente cliente3 = {3, "Cliente 3"};

    enfileirar(fila, &cliente1);
    enfileirar(fila, &cliente2);
    enfileirar(fila, &cliente3);

    printf("Atendimento no banco:\n");

    while (!fila_vazia(fila)) {
        Cliente* proximo_cliente = desenfileirar(fila);
        printf("Atendendo Cliente %d: %s\n", proximo_cliente->id, proximo_cliente->nome);
    }

    destruir_fila(fila);

    return 0;
}
