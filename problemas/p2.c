#include "listac.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void inserir_unico(ListaC* p_lista, char* descricao, int preco) {
    // implementar
}

int main(void) {
    // Cria uma lista vazia
    ListaC lista = {.inicio = NULL, .comprimento = 0};
    printf("A lista vazia tem %d itens:\n", lista.comprimento);
    imprimir(lista);

    // Insere alguns itens
    inserir_unico(&lista, "Carne", 3050);
    inserir_unico(&lista, "Carne", 10);
    inserir_unico(&lista, "Tomate", 40);
    inserir_unico(&lista, "Tomate", 1020);
    inserir_unico(&lista, "Creme de leite", 2030);
    inserir_unico(&lista, "Caneta", 60);
    printf("A lista toda tem %d itens:\n", lista.comprimento);
    imprimir(lista);

    // Libera a memória
    limpar(&lista);
    printf("A lista vazia tem %d itens:\n", lista.comprimento);
    imprimir(lista);

    return 0;
}
