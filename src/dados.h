/**
 * @file dados.h
 * @author Rodrigo Miranda (a31509@alunos.ipca.pt)
 * @brief Ficheiro de cabeçalho dedicado à definição de structs e outros tipos de dados utilizados no programa.
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>

/**
 * @struct Antenas
 * @brief Estrutura que representa uma antena com coordenadas e frequência.
 * 
 * Esta estrutura é utilizada para criar uma lista ligada de antenas, onde cada node 
 * contém as coordenadas da antena (x, y), a sua frequência e um ponteiro para o próximo node.
 */
typedef struct Antenas{
    int x, y; /**< Coordenada X e Y da antena */
    char freq; /**< Frequencia da antena representada por um caracter */
    struct Antenas *prox; /**< Ponteiro para o proximo node da lista */
}Antenas;

/**
 * @struct ListaEfeitoNefasto
 * @brief Estrutura que representa o efeito nefasto e as suas coordenadas
 * 
 * Esta estrutura é utilizada para criar uma lista ligada do efeito nefasto, onde cada node 
 * contém as coordenadas da antena (x, y) e um ponteiro para o proximo node
 */
typedef struct ListaEfeitoNefasto {
    int x, y; /**< Coordenada X e Y do efeito nefasto */
    struct ListaEfeitoNefasto *prox; /**< Ponteiro para o próximo node da lista */
} ListaEfeitoNefasto;

/**
 * @struct AntenasBin
 * @brief Estrutura que representa uma antena com coordenadas e frequência.
 * 
 * Esta estrutura é utilizada para gravar num ficheiro binario
 * contém as coordenadas da antena (x, y) e a sua frequência
 */
typedef struct AntenasBin{
    int x, y; /**< Coordenada X e Y da antena */
    char freq; /**< Frequencia da antena representada por um caracter */
}AntenasBin;