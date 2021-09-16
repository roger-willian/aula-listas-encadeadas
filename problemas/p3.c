#include "listad.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/** Coloca um novo elemento na pilha */
void empilhar(ListaD* p_lista, char* descricao, int preco) {
    // implementar
}

/** Retira um elemento da pilha */
ItemD desempilhar(ListaD* p_lista) {
    // implementar
}

int main(void) {
    // Cria uma pilha vazia e insere alguns itens
    ListaD lista = {.inicio = NULL, .fim = NULL, .comprimento = 0};
    empilhar(&lista, "Carne", 3050);
    desempilhar(&lista);
    empilhar(&lista, "Carne", 10);
    empilhar(&lista, "Tomate", 40);
    empilhar(&lista, "Tomate", 1020);
    desempilhar(&lista);
    empilhar(&lista, "Creme de leite", 2030);
    empilhar(&lista, "Caneta", 60);
    // Imprime a altura da pilha
    printf("A pilha toda tem %d itens:\n", lista.comprimento);
    while (lista.comprimento) {
        ItemD item = desempilhar(&lista);
        printf("%-20s R$ %6.2f\n", item.descricao, item.preco/100.0);
    }
    return 0;
}
