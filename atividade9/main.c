#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <time.h>

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

    /*atividade9*/
    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    FILE* arquivo = fopen("1kk_rand_float.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[256];
    float numero;

    clock_t inicio, fim;
    double tempo_total_nao_ordenado = 0.0;
    double tempo_total_ordenado = 0.0;
    int num_insercoes = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numero = strtof(linha, NULL);

        No* novo_no = no(numero, NULL);

        // Mede o tempo de inserção na lista não ordenada.
        inicio = clock();
        lista_inserir_no(novo_no, lista_nao_ordenada);
        fim = clock();
        tempo_total_nao_ordenado += (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Mede o tempo de inserção na lista ordenada.
        inicio = clock();
        lista_inserir_no_ordenado(lista_ordenada, novo_no);
        fim = clock();
        tempo_total_ordenado += (double)(fim - inicio) / CLOCKS_PER_SEC;

        num_insercoes++;
    }

    fclose(arquivo);

    // Calcula o tempo médio de inserção em ambas as listas.
    double tempo_medio_nao_ordenado = tempo_total_nao_ordenado / num_insercoes;
    double tempo_medio_ordenado = tempo_total_ordenado / num_insercoes;

    printf("Tempo medio de insercao na lista nao ordenada: %f segundos\n", tempo_medio_nao_ordenado);
    printf("Tempo medio de insercao na lista ordenada: %f segundos\n", tempo_medio_ordenado);

    // Libere a memória das listas quando não forem mais necessárias.
    lista_liberar(lista_nao_ordenada);
    lista_liberar(lista_ordenada);

    // Verifique a existência de um valor
    char valor_busca = 'D';
    int existe = lista_verificar_existencia(n0, valor_busca);
    printf("\nO valor '%c' existe na lista: %s", valor_busca, existe ? "Sim" : "Nao");

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
