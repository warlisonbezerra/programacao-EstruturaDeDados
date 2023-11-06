#include <stdio.h>
#include "tabela_hash.h"

int main() {
    // Exemplo de uso da tabela hash
    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");

    char* resultado1 = hash_table_get("chave1");
    char* resultado2 = hash_table_get("chave2");
    char* resultado3 = hash_table_get("chave3");

    printf("Resultado 1: %s\n", resultado1); // Deve imprimir "valor1"
    printf("Resultado 2: %s\n", resultado2); // Deve imprimir "valor2"
    printf("Resultado 3: %s\n", resultado3); // Deve imprimir "Resultado 3: (null)"

    // Removendo uma chave
    hash_table_remove("chave1");
    char* resultado4 = hash_table_get("chave1");
    printf("Resultado 4: %s\n", resultado4); // Deve imprimir "Resultado 4: (null)"

    return 0;
}
