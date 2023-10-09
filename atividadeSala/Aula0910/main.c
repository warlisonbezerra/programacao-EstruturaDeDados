#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(int argc, char const *argv[])
{
    /*Adicionando os ponteiros dos nós da lista*/
    No* n0 = no('C', NULL); /*Cada nó guarda um respectivo valor, como 'C' e aponta para o próximo que é nulo*/
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('F', no('W', no('K', NULL))))));

    lista_inserir_no(n0,n1); /*Módulo para mostrar os nós, iniciando pelo n0 e apontando para o n1*/
    lista_inserir_no(n0,n2);

    lista_imprimir(n0); /*Imprimir a lista encadeada*/

    printf("\nqtd nos: %d", lista_quantidade_nos(n0));

    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia);
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);
    lista_liberar(n0);
    lista_imprimir(n0);

    exit(0);
}
