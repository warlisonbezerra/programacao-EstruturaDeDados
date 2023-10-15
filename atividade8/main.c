#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia);
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);
    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);

    // Verifique a existência de um valor
    char valor_busca = 'D';
    int existe = lista_verificar_existencia(n0, valor_busca);
    printf("\nO valor '%c' existe na lista: %s", valor_busca, existe ? "Sim" : "Não");

    // Verifique a quantidade de ocorrências de um valor
    int ocorrencias = lista_verificar_ocorrencias(n0, valor_busca);
    printf("\nO valor '%c' ocorre %d vezes na lista", valor_busca, ocorrencias);

    // Imprima a lista na ordem inversa
    printf("Lista na ordem inversa: ");
    lista_imprimir_inversa(n0);

    // Insira um nó na posição 2 (índice 2)
    lista_inserir_no_i(n0, 2);
    printf("\nApós inserção na posição 2: ");
    lista_imprimir(n0);

    // Remova o nó na posição 4 (índice 4)
    lista_remover_no_i(n0, 4);
    printf("\nApós remoção na posição 4: ");
    lista_imprimir(n0);

    // Remova todos os nós com valor 'D'
    lista_remover_no(n0, 'D');
    printf("\nApós remoção de todos os nós 'D': ");
    lista_imprimir(n0);

    // Libere a memória da lista
    lista_liberar(n0);
    n0 = NULL;

    exit(0);
}
