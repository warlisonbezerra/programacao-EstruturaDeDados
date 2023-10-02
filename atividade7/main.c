#include <stdio.h>
#include "pilha.h"
#include "pilha.c"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    Pilha* historico = criar_pilha();

    push(historico, "www.example.com");
    push(historico, "www.google.com");
    push(historico, "www.openai.com");

    printf("Página atual: %s\n", top(historico));

    printf("Navegando para a página anterior...\n");
    pop(historico);

    printf("Página atual: %s\n", top(historico));

    destruir_pilha(historico);

    return 0;
}
