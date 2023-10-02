#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define MAX_PAGINAS 100

struct Pilha {
    const char* paginas[MAX_PAGINAS];
    int topo;
};

Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = -1;
    return pilha;
}

void destruir_pilha(Pilha* pilha) {
    free(pilha);
}

void push(Pilha* pilha, const char* pagina) {
    if (pilha->topo < MAX_PAGINAS - 1) {
        pilha->topo++;
        pilha->paginas[pilha->topo] = strdup(pagina);
    }
}

void pop(Pilha* pilha) {
    if (pilha->topo >= 0) {
        free((void*)pilha->paginas[pilha->topo]);
        pilha->topo--;
    }
}

const char* top(Pilha* pilha) {
    if (pilha->topo >= 0) {
        return pilha->paginas[pilha->topo];
    }
    return NULL;
}

int vazia(Pilha* pilha) {
    return pilha->topo == -1;
}
