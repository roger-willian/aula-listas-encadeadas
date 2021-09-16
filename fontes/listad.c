/** @file listad.c
 * Uma implementação de uma lista duplamente encadeada.
 */

#include "listad.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Pega uma cópia isolada de um item da lista
ItemD pegar(ListaD lista, int posicao) {
    int N = lista.comprimento;
    // posições vão de 0 até N-1
    if (posicao < 0 || posicao > N - 1) {
        printf("A posição %d não é uma posição válida!\n", posicao);
        exit(EXIT_FAILURE);
    }

    // percorre a lista buscando o item
    ItemD* atual = lista.inicio;
    for(int i=0; i<posicao; i++) {
        atual = atual->proximo;
    }

    // cria uma cópia do item
    ItemD copia;
    memcpy(&copia, atual, sizeof(ItemD));
    copia.anterior = NULL;
    copia.proximo = NULL;
    return copia;
}

// Função interna, insere um item no início da lista
static void _inserir_inicio(ListaD* lista, ItemD* novo) {
    ItemD* proximo = lista->inicio;
    novo->proximo = proximo;
    novo->anterior = NULL;
    lista->inicio = novo;
    proximo->anterior = novo;
    lista->comprimento++;
}

// Função interna, insere um item no fim da lista
static void _inserir_fim(ListaD* lista, ItemD* novo) {
    ItemD* anterior = lista->fim;
    novo->proximo = NULL;
    novo->anterior = anterior;
    anterior->proximo = novo;
    lista->fim = novo;
    lista->comprimento++;
}

// Função interna, insere um item em uma lista vazia
static void _inserir_unico(ListaD* lista, ItemD* novo) {
    novo->anterior = NULL;
    novo->proximo = NULL;
    lista->inicio = novo;
    lista->fim = novo;
    lista->comprimento++;
}

// Função interna, insere um item no miolo da lista
static void _inserir_meio(ListaD* lista, int posicao, ItemD* novo) {
    ItemD* proximo = lista->inicio;
    for (int i=0; i<posicao; i++) {
        proximo = proximo->proximo;
    }
    ItemD* anterior = proximo->anterior;
    novo->proximo = proximo;
    novo->anterior = anterior;
    anterior->proximo = novo;
    proximo->anterior = novo;
    lista->comprimento++;
}

// Insere um novo item na lista
void inserir(ListaD* lista, int posicao, char* descricao, int preco) {
    int N = lista->comprimento;
    // só insere antes do primeiro até logo após o último
    if (posicao < 0 || posicao > N) {
        printf("A posição %d não é uma posição válida!\n", posicao);
        exit(EXIT_FAILURE);
    }

    // cria um novo item para ser inserido
    ItemD* novo = malloc(sizeof(ItemD));
    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }
    novo->preco = preco;
    strncpy(novo->descricao, descricao, MAXDESC);

    if (N == 0)
        _inserir_unico(lista, novo);
    else if (posicao == 0)
        _inserir_inicio(lista, novo);
    else if (posicao == N)
        _inserir_fim(lista, novo);
    else
        _inserir_meio(lista, posicao, novo);
}

// Função interna, remove o primeiro item da lista
static void _remover_inicio(ListaD* lista) {
    // marca o primeiro item para remoção
    ItemD* deletar = lista->inicio;
    ItemD* proximo = deletar->proximo;
    proximo->anterior = NULL;
    lista->inicio = proximo;
    free(deletar);
    deletar = NULL;
    lista->comprimento--;
}

// Função interna, remove o último item da lista
static void _remover_fim(ListaD* lista) {
    // marca último item para remoção
    ItemD* deletar = lista->fim;
    ItemD* anterior = deletar->anterior;
    anterior->proximo = NULL;
    lista->fim = anterior;
    free(deletar);
    deletar = NULL;
    lista->comprimento--;
}

// Função interna, remove um item do miolo da lista
static void _remover_meio(ListaD* lista, int posicao) {
    ItemD* deletar = lista->inicio;
    for (int i=0; i<posicao; i++)
        deletar = deletar->proximo;
    ItemD* anterior = deletar->anterior;
    ItemD* proximo = deletar->proximo;
    anterior->proximo = proximo;
    proximo->anterior = anterior;
    free(deletar);
    deletar = NULL;
    lista->comprimento--;
}

// Remove um item da lista
void remover(ListaD* lista, int posicao) {
    int N = lista->comprimento;
    // os itens têm índices de 0 até N-1
    if (posicao < 0 || posicao > N - 1) {
        printf("A posição %d não é uma posição válida!\n", posicao);
        exit(EXIT_FAILURE);
    }

    if (N == 1) {
        limpar(lista);
    } else if (posicao == 0) {
        _remover_inicio(lista);
    } else if (posicao == N-1) {
        _remover_fim(lista);
    } else {
        _remover_meio(lista, posicao);
    }
}

// Destrói a lista liberando a memória
void limpar(ListaD* lista) {
    // percorre a lista destruindo os itens
    ItemD* proximo = lista->inicio;
    ItemD* deletar = NULL;
    while (proximo != NULL) {
        deletar = proximo;
        proximo = deletar->proximo;
        free(deletar);
        deletar = NULL;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->comprimento = 0;
}

// Imprime os itens da lista na tela
void imprimir(ListaD lista) {
    // percorre a lista imprimindo os itens
    ItemD *atual = lista.inicio;
    while (atual != NULL) {
        printf("%-20s R$ %6.2f\n", atual->descricao, atual->preco/100.0);
        atual = atual->proximo;
    }
}

// Reverte a ordem dos itens da lista
void reverter(ListaD* lista) {
    // percorre a lista revertendo os ponteiros
    ItemD *atual = lista->fim;
    ItemD *aux = NULL;
    while (atual != NULL) {
        aux = atual->anterior;
        atual->anterior = atual->proximo;
        atual->proximo = aux;
        atual = aux;
    }
    aux = lista->inicio;
    lista->inicio = lista->fim;
    lista->fim = aux;
}