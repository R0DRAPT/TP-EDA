/**
 * @file main.c
 * @author Rodrigo Miranda (a31509@alunos.ipca.pt)
 * @brief Ficheiro principal do programa.
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    // Ponteiro para a lista de antenas
    Antenas* listaAntenas = NULL;

    //Lista o mapa das antenas
    ListarMapaAntenas();

    //Criar e insere a antena no fim da lista
    listaAntenas = CriarAntenaFim(listaAntenas, 'A', 1, 3);

    //Lista uma antena
    ListarAntenas(listaAntenas);

    return 0;   
}