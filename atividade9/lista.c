#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


No* no(float valor, No* proximo_no) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo_no = proximo_no;
    return novo_no;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L){
    if(L != NULL){
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }
}

int lista_verificar_existencia(No* L, float valor_busca) {
    while (L != NULL) {
        if (L->valor == valor_busca) {
            return 1;
        }
        L = L->proximo_no;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, float valor_busca) {
    int count = 0;
    while (L != NULL) {
        if (L->valor == valor_busca) {
            count++;
        }
        L = L->proximo_no;
    }
    return count;
}

void lista_imprimir_inversa(No* L) {
    if (L == NULL) {
        return;
    }
    lista_imprimir_inversa(L->proximo_no);
    printf("%c ", L->valor);
}

void lista_inserir_no_i(No* L, int i) {
    if (i == 0) {
        No* novo_no = no('N', L->proximo_no);
        L->proximo_no = novo_no;
    } else {
        lista_inserir_no_i(L->proximo_no, i - 1);
    }
}

void lista_remover_no_i(No* L, int i) {
    if (i == 0 && L->proximo_no != NULL) {
        No* temp = L->proximo_no;
        L->proximo_no = L->proximo_no->proximo_no;
        free(temp);
    } else {
        lista_remover_no_i(L->proximo_no, i - 1);
    }
}

void lista_remover_no(No* L, float valor_busca) {
    No* atual = L;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            if (anterior == NULL) {
                L = atual->proximo_no;
            } else {
                anterior->proximo_no = atual->proximo_no;
            }
            free(atual);
            atual = anterior ? anterior->proximo_no : L;
        } else {
            anterior = atual;
            atual = atual->proximo_no;
        }
    }
}

void lista_inserir_no_ordenado(No* L, No* no) {
    if (L == NULL) {
        // Se a lista estiver vazia, insira o nó como o primeiro elemento.
        L = no;
        return;
    }

    if (no->valor < L->valor) {
        // Se o valor do nó é menor do que o valor do primeiro nó na lista, insira o nó como o novo primeiro elemento.
        no->proximo_no = L;
        L = no;
        return;
    }

    No* atual = L;
    while (atual->proximo_no != NULL && no->valor > atual->proximo_no->valor) {
        atual = atual->proximo_no;
    }

    no->proximo_no = atual->proximo_no;
    atual->proximo_no = no;
}

