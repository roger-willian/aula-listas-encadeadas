/** @file lista.c
 * Uma implementação de uma lista encadeada sem cabeça.
 */

#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Pega uma cópia isolada de um item da lista
Item pegar(Lista lista, int posicao) {
    int N = comprimento(lista);
    // posições vão de 0 até N-1
    if (posicao < 0 || posicao > N - 1) {
        printf("A posição %d não é uma posição válida!\n", posicao);
        exit(EXIT_FAILURE);
    }

    // percorre a lista buscando o item
    Item* atual = (Item*) lista;
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
static void _inserir_inicio(Lista* p_lista, Item* novo) {
    Item* inicio = (*p_lista);
    novo->proximo = inicio;
    (*p_lista) = novo;
}

// Função interna, insere um item da segunda posição para a frente
static void _inserir_meio(Lista* p_lista, int posicao, Item* novo) {
    // p_lista aponta para a lista e a lista aponta para o início
    Item* anterior = (*p_lista);
    for (int i=1; i<posicao; i++) {
        anterior = anterior->proximo;
    }
    novo->proximo = anterior->proximo;
    anterior->proximo = novo;
}

// Insere um novo item na lista
void inserir(Lista* p_lista, int posicao, char* descricao, int preco) {
    int N = comprimento(*p_lista);
    // só insere antes do primeiro até logo após o último
    if (posicao < 0 || posicao > N) {
        printf("A posição %d não é uma posição válida!\n", posicao);
        exit(EXIT_FAILURE);
    }

    // cria o novo item para ser inserido
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
static void _remover_inicio(Lista* p_lista) {
    Item* deletar = (Item*) (*p_lista);
    Item* proximo = deletar->proximo;
    (*p_lista) = proximo;
    free(deletar);
    deletar = NULL;
}

// Função interna, remove um item da segunda posição para a frente
static void _remover_meio(Lista* p_lista, int posicao) {
    Item* anterior = (Item*) (*p_lista);
    for (int i=1; i<posicao; i++) {
        anterior = anterior->proximo;
    }
    Item* deletar = anterior->proximo;
    anterior->proximo = deletar->proximo;
    free(deletar);
    deletar = NULL;
}

// Remove um item da lista
void remover(Lista* p_lista, int posicao) {
    int N = comprimento(*p_lista);
    // posições vão de 0 até N-1
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

// Número de itens da lista
int comprimento(Lista lista) {
    int i=0;
    // percorre a lista contando os itens
    Item* atual = (Item*) lista;
    while (atual != NULL) {
        atual = atual->proximo;
        i++;
    }
    return i;
}

// Destrói a lista liberando a memória
void limpar(Lista* p_lista) {
    // percorre a lista destruindo os itens
    Item* atual = (Item*) (*p_lista);
    Item* deletar = NULL;
    while (atual != NULL) {
        deletar = atual;
        atual = atual->proximo;
        free(deletar);
        deletar = NULL;
    }
    (*p_lista) = NULL;
}

// Imprime os itens da lista na tela
void imprimir(Lista lista) {
    // percorre a lista imprimindo os itens
    Item *atual = (Item*) lista;
    while (atual != NULL) {
        printf("%-20s R$ %6.2f\n", atual->descricao, atual->preco/100.0);
        atual = atual->proximo;
    }
}
