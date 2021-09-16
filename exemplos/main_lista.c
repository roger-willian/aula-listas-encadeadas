#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    // Cria uma lista vazia
    Lista lista = NULL;
    printf("A lista vazia tem %d itens:\n", comprimento(lista));
    imprimir(lista);

    // Insere alguns itens
    inserir(&lista, 0, "Carne", 3050);
    inserir(&lista, 0, "Carne", 10);
    inserir(&lista, 1, "Tomate", 40);
    inserir(&lista, 1, "Tomate", 1020);
    inserir(&lista, 2, "Creme de leite", 2030);
    inserir(&lista, 5, "Caneta", 60);
    printf("A lista toda tem %d itens:\n", comprimento(lista));
    imprimir(lista);

    // Remove alguns itens
    remover(&lista, 0);
    remover(&lista, 2);
    remover(&lista, 3);
    printf("A lista toda tem %d itens:\n", comprimento(lista));
    imprimir(lista);

    // Pega o último item e imprime
    int N = comprimento(lista);
    Item item = pegar(lista, N-1);
    printf("O item #%d (último) da lista:\n", N);
    printf("%-20s R$ %6.2f\n", item.descricao, item.preco/100.0);

    // Libera a memória
    limpar(&lista);
    printf("A lista vazia tem %d itens:\n", comprimento(lista));
    imprimir(lista);

    return 0;
}
