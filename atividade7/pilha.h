#ifndef PILHA_H //verificar
#define PILHA_H

typedef struct Pilha Pilha;

Pilha* criar_pilha();
void destruir_pilha(Pilha* pilha);
void push(Pilha* pilha, const char* pagina);
void pop(Pilha* pilha);
const char* top(Pilha* pilha);
int vazia(Pilha* pilha);

#endif
