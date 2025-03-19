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
 * Esta estrutura é utilizada para criar uma lista ligada de antenas, onde cada nó 
 * contém as coordenadas da antena (x, y), a sua frequência e um ponteiro para o próximo nó.
 */
typedef struct Antenas{
    float x, y; /**< Coordenada X e Y da antena */
    char freq; /**< Frequencia da antena representada por um caracter */
    struct Antenas *prox; /**< Ponteiro para o proximo nó da lista */
}Antenas;