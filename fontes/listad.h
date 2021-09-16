/** @file listad.h
 * Uma interface de uma lista duplamente encadeada.
 */

#ifndef LISTAD_H
#define LISTAD_H

/** Número máximo de caracteres na descrição de cada ::ItemD. */
#define MAXDESC 20

/** Esta estrutura representa um único item de uma ::ListaD. */
typedef struct s_item {
    int preco;                      ///< Preço do ::ItemD em centavos
    char descricao[MAXDESC+1];      ///< Descrição do ::ItemD
    struct s_item* proximo;         ///< Ponteiro para o próximo ::ItemD
    struct s_item* anterior;        ///< Ponteiro para o ::ItemD anterior
} ItemD;

/** Uma ::ListaD duplamente encadeada é definida pela sua própria cabeça. */
typedef struct s_cabeca {
    ItemD* inicio;
    ItemD* fim;
    int comprimento;
} ListaD;

/**
 * Pega um ::ItemD em determinada posição sem removê-lo. Se a posição for
 * inválida encerra o programa com erro.
 * @param lista A cabeça da ::ListaD.
 * @param posicao A posição do ::ItemD que se busca.
 * @return O ::ItemD daquela posição.
 */
ItemD pegar(ListaD lista, int posicao);

/**
 * Insere um novo ::ItemD em determinada posição. Se a posição for inválida
 * encerra o programa com erro.
 * @param lista Um ponteiro para a cabeça da ::ListaD.
 * @param posicao A posição em que dever ser inserido o ::ItemD.
 * @param descricao A descrição do ::ItemD.
 * @param preco O preço do ::ItemD em centavos.
 */
void inserir(ListaD* lista, int posicao, char* descricao, int preco);

/**
 * Remove um ::ItemD de determinada posição da ::ListaD. Se a posição for
 * inválida encerra o programa com erro.
 * @param lista Um ponteiro para a cabeça da ::ListaD.
 * @param posicao A posição do ::ItemD a ser removido.
 */
void remover(ListaD* lista, int posicao);

/**
 * Destrói cada ::ItemD da ::ListaD liberando a memória.
 * @param lista Um ponteiro para a cabeça da ::ListaD.
 */
void limpar(ListaD* lista);

/**
 * Imprime na tela cada ::ItemD da ::ListaD na ordem em que está armazenado.
 * @param lista A cabeça da ::ListaD a ser impressa. 
 */
void imprimir(ListaD lista);

/**
 * Reverte a ordem dos itens da lista.
 * @param lista A cabeça da ::ListaD a ser revertida. 
 */
void reverter(ListaD* lista);

#endif