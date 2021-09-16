/** @file listac.h
 * Uma interface de uma lista encadeada com cabeça.
 */

#ifndef LISTAC_H
#define LISTAC_H

/** Número máximo de caracteres na descrição de cada ::Item. */
#define MAXDESC 20

/** Esta estrutura representa um único item de uma ::ListaC. */
typedef struct s_item {
    int preco;                      ///< Preço do ::Item em centavos
    char descricao[MAXDESC+1];      ///< Descrição do ::Item
    struct s_item* proximo;         ///< Ponteiro para o próximo ::Item
} Item;

/** Uma ::ListaC encadeada com cabeça é definida pela sua própria cabeça. */
typedef struct s_cabeca {
    Item* inicio;
    int comprimento;
} ListaC;

/**
 * Pega um ::Item em determinada posição sem removê-lo. Se a posição for
 * inválida encerra o programa com erro.
 * @param lista A cabeça da ::ListaC.
 * @param posicao A posição do ::Item que se busca.
 * @return O ::Item daquela posição.
 */
Item pegar(ListaC lista, int posicao);

/**
 * Insere um novo ::Item em determinada posição. Se a posição for inválida
 * encerra o programa com erro.
 * @param p_lista Um ponteiro para a cabeça da ::ListaC.
 * @param posicao A posição em que dever ser inserido o ::Item.
 * @param descricao A descrição do ::Item.
 * @param preco O preço do ::Item em centavos.
 */
void inserir(ListaC* p_lista, int posicao, char* descricao, int preco);

/**
 * Remove um ::Item de determinada posição da ::ListaC. Se a posição for
 * inválida encerra o programa com erro.
 * @param p_lista Um ponteiro para a cabeça da ::ListaC.
 * @param posicao A posição do ::Item a ser removido.
 */
void remover(ListaC* p_lista, int posicao);

/**
 * Destrói cada ::Item da ::ListaC liberando a memória.
 * @param p_lista Um ponteiro para a cabeça da ::ListaC.
 */
void limpar(ListaC* p_lista);

/**
 * Imprime na tela cada ::Item da ::ListaC na ordem em que está armazenado.
 * @param lista A cabeça da ::ListaC a ser impressa. 
 */
void imprimir(ListaC lista);

#endif