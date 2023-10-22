#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    float valor; // Agora, a estrutura No armazena valores do tipo float
    struct No* proximo_no;
} No;

No* no(float valor, No* proximo_no);
int lista_verificar_existencia(No* L, float valor_busca);
int lista_verificar_ocorrencias(No* L, float valor_busca);
void lista_imprimir_inversa(No* L);
void lista_inserir_no_i(No* L, int i);
void lista_remover_no_i(No* L, int i);
void lista_remover_no(No* L, float valor_busca);
void lista_inserir_no_ordenado(No* L, No* no); // Declaração da função

void lista_inserir_no(No* L, No* no);
void lista_imprimir(No* L);
int lista_quantidade_nos(No* L);
No* lista_copiar(No* L);
void lista_concatenar(No* L, No* Lc);
void lista_liberar(No* L);

#endif
