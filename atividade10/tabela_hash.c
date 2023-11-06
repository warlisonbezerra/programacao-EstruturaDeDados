#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define TABLE_SIZE 100

// Definindo a estrutura da tabela hash
typedef struct {
    char* chave;
    char* dado;
} HashEntry;

HashEntry* tabela_hash[TABLE_SIZE];

// Função hash simples
int hash(char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TABLE_SIZE;
}

char* hash_table_get(char* chave) {
    int indice = hash(chave);
    HashEntry* entry = tabela_hash[indice];

    if (entry != NULL && strcmp(entry->chave, chave) == 0) {
        return entry->dado;
    }

    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int indice = hash(chave);
    HashEntry* new_entry = (HashEntry*)malloc(sizeof(HashEntry));
    new_entry->chave = strdup(chave);
    new_entry->dado = strdup(dado);

    tabela_hash[indice] = new_entry;
}

int hash_table_contains(char* chave) {
    int indice = hash(chave);
    HashEntry* entry = tabela_hash[indice];

    return (entry != NULL && strcmp(entry->chave, chave) == 0);
}

void hash_table_remove(char* chave) {
    int indice = hash(chave);
    HashEntry* entry = tabela_hash[indice];

    if (entry != NULL && strcmp(entry->chave, chave) == 0) {
        free(entry->chave);
        free(entry->dado);
        free(entry);
        tabela_hash[indice] = NULL;
    }
}
