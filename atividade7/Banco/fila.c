#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criar_fila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL) {
        perror("Erro ao alocar memória para a fila");
        exit(EXIT_FAILURE);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void destruir_fila(Fila* fila) {
    while (!fila_vazia(fila)) {
        desenfileirar(fila);
    }
    free(fila);
}

int fila_vazia(Fila* fila) {
    return fila->inicio == NULL;
}

void enfileirar(Fila* fila, Cliente* cliente) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        perror("Erro ao alocar memória para o nó da fila");
        exit(EXIT_FAILURE);
    }
    novo_no->cliente = *cliente;
    novo_no->proximo = NULL;

    if (fila_vazia(fila)) {
        fila->inicio = novo_no;
        fila->fim = novo_no;
    } else {
        fila->fim->proximo = novo_no;
        fila->fim = novo_no;
    }
}

Cliente* desenfileirar(Fila* fila) {
    if (fila_vazia(fila)) {
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);
    }

    No* no_removido = fila->inicio;
    Cliente* cliente = &(no_removido->cliente);

    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(no_removido);

    return cliente;
}
