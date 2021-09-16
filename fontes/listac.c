/** @file listac.c
 * Uma implementação de uma lista encadeada com cabeça.
 */

#include "listac.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Pega uma cópia isolada de um item da lista
Item pegar(ListaC lista, int posicao) {
    int N = lista.comprimento;
    // posições vão de 0 até N-1
    if (posicao < 0 || posicao > N - 1) {
        printf("A posição %d não é uma posição válida!\n", posicao);
        exit(EXIT_FAILURE);
    }

    // percorre a lista buscando o item
    Item* atual = lista.inicio;
    for(int i=0; i<posicao; i++) {
        atual = atual->proximo;
    }
    // cria uma cópia do item
    Item copia;
    memcpy(&copia, atual, sizeof(Item));
    copia.proximo = NULL;
    return copia;
}

// Função interna, insere um item no início da lista
static void _inserir_inicio(ListaC* p_lista, Item* novo) {
    novo->proximo = p_lista->inicio;
    p_lista->inicio = novo;
    p_lista->comprimento++;
}

// Função interna, insere um item da segunda posição para a frente
static void _inserir_meio(ListaC* p_lista, int posicao, Item* novo) {
    Item* anterior = p_lista->inicio;
    for (int i=1; i<posicao; i++) {
        anterior = anterior->proximo;
    }
    novo->proximo = anterior->proximo;
    anterior->proximo = novo;
    p_lista->comprimento++;
}

// Insere um novo item na lista
void inserir(ListaC* p_lista, int posicao, char* descricao, int preco) {
    int N = p_lista->comprimento;
    // só insere antes do primeiro até logo após o último
    if (posicao < 0 || posicao > N) {
        printf("A posição %d não é uma posição válida!\n", posicao);
        exit(EXIT_FAILURE);
    }

    // cria um novo item para ser inserido
    Item* novo = malloc(sizeof(Item));
    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }
    novo->preco = preco;
    strncpy(novo->descricao, descricao, MAXDESC);

    if (posicao == 0) {
        _inserir_inicio(p_lista, novo);
    } else {
        _inserir_meio(p_lista, posicao, novo);
    }
}

// Função interna, remove o primeiro item da lista
static void _remover_inicio(ListaC* p_lista) {
    Item* deletar = p_lista->inicio;
    p_lista->inicio = deletar->proximo;
    free(deletar);
    deletar = NULL;
    p_lista->comprimento--;
}

// Função interna, remove um item da segunda posição para a frente
static void _remover_meio(ListaC* p_lista, int posicao) {
    Item* anterior = p_lista->inicio;
    for (int i=1; i<posicao; i++) {
        anterior = anterior->proximo;
    }
    Item* deletar = anterior->proximo;
    anterior->proximo = deletar->proximo;
    free(deletar);
    deletar = NULL;
    p_lista->comprimento--;
}

// Remove um item da lista
void remover(ListaC* p_lista, int posicao) {
    int N = p_lista->comprimento;
    // os itens têm índices de 0 até N-1
    if (posicao < 0 || posicao > N - 1) {
        printf("A posição %d não é uma posição válida!\n", posicao);
        exit(EXIT_FAILURE);
    }

    if (posicao == 0) {
        _remover_inicio(p_lista);
    } else {
        _remover_meio(p_lista, posicao);
    }
}

// Destrói a lista liberando a memória
void limpar(ListaC* p_lista) {
    // percorre a lista destruindo os itens
    Item* atual = p_lista->inicio;
    Item* deletar = NULL;
    while (atual != NULL) {
        deletar = atual;
        atual = atual->proximo;
        free(deletar);
        deletar = NULL;
    }
    p_lista->inicio = NULL;
    p_lista->comprimento = 0;
}

// Imprime os itens da lista na tela
void imprimir(ListaC lista) {
    // percorre a lista imprimindo os itens
    Item *atual = lista.inicio;
    while (atual != NULL) {
        printf("%-20s R$ %6.2f\n", atual->descricao, atual->preco/100.0);
        atual = atual->proximo;
    }
}