#ifndef FILA_H
#define FILA_H

// Estrutura para representar um cliente no banco
typedef struct Cliente {
    int id;
    char nome[50];
} Cliente;

// Estrutura para representar um nó na fila
typedef struct No {
    Cliente cliente;
    struct No* proximo;
} No;

// Estrutura para representar a fila
typedef struct Fila {
    No* inicio;
    No* fim;
} Fila;

Fila* criar_fila();
void destruir_fila(Fila* fila);
int fila_vazia(Fila* fila);
void enfileirar(Fila* fila, Cliente* cliente);
Cliente* desenfileirar(Fila* fila);

#endif
