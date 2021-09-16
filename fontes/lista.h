/** @file lista.h
 * Uma interface de uma lista encadeada sem cabeça.
 */

#ifndef LISTA_H
#define LISTA_H

/** Número máximo de caracteres na descrição de cada ::Item. */
#define MAXDESC 20

/** Esta estrutura representa um único item de uma ::Lista. */
typedef struct s_item {
    char descricao[MAXDESC+1];      ///< Descrição do ::Item
    int preco;                      ///< Preço do ::Item em centavos
    struct s_item* proximo;         ///< Ponteiro para o próximo ::Item
} Item;

/**
 * Uma ::Lista encadeada é uma sequência de itens. Portanto, com um pequeno
 * abuso de notação, uma ::Lista encadeada um ponteiro para seu primeiro ::Item.
 */
typedef Item* Lista;

/**
 * Pega um ::Item em determinada posição sem removê-lo. Se a posição for
 * inválida encerra o programa com erro.
 * @param lista Um ponteiro para o início da ::Lista.
 * @param posicao A posição do ::Item que se busca.
 * @return O ::Item daquela posição.
 */
Item pegar(Lista lista, int posicao);

/**
 * Insere um novo ::Item em determinada posição. Se a posição for inválida
 * encerra o programa com erro.
 * @param p_lista Um ponteiro para a ::Lista.
 * @param posicao A posição em que dever ser inserido o ::Item.
 * @param descricao A descrição do ::Item.
 * @param preco O preço do ::Item em centavos.
 */
void inserir(Lista* p_lista, int posicao, char* descricao, int preco);

/**
 * Remove um ::Item de determinada posição da ::Lista. Se a posição for inválida
 * encerra o programa com erro.
 * @param p_lista Um ponteiro para a ::Lista.
 * @param posicao A posição do ::Item a ser removido.
 */
void remover(Lista* p_lista, int posicao);

/**
 * Número de itens na ::Lista.
 * @param lista Um ponteiro para o início da ::Lista.
 * @return O número de ::Item%s da ::Lista.
 */
int comprimento(Lista lista);

/**
 * Destrói cada ::Item da ::Lista liberando a memória.
 * @param p_lista Um ponteiro para a ::Lista.
 */
void limpar(Lista* p_lista);

/**
 * Imprime na tela cada ::Item da lista na ordem em que está armazenado.
 * @param lista Um ponteiro para o início da ::Lista a ser impressa. 
 */
void imprimir(Lista lista);

#endif