/**
 * @file funcoes.c
 * @author Rodrigo Miranda (a31509@alunos.ipca.pt)
 * @brief Ficheiro de implementação das funções utilizadas no programa. Contém a lógica das operações definidas em funcoes.h
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

/**
 * @brief Lê o ficheiro "mapaAntenas.txt" e imprime o seu conteúdo no terminal.
 * 
 * A função abre o ficheiro localizado na pasta "FicheirosTexto" e exibe as informações
 * armazenadas nele.
 * 
 * @return Retorna NULL pois não altera a lista ligada, apenas exibe os dados.
 */
Antenas* ListarMapaAntenas() {
    FILE *file = fopen("FicheirosTexto/mapaAntenas.txt", "r");
    //Verefica se o ficheiro existe
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro mapaAntenas.txt!\n");
        return NULL;
    }
    //Se existir
    printf("Conteúdo do ficheiro 'mapaAntenas.txt':\n");
    char linha[100]; // Armazena temporariamente cada linha do ficheiro a medida que é lida

    while (fgets(linha, sizeof(linha), file) != NULL) { // (Linha armazenada / Nº Maximo de caracteres a ler / apontador para variaveis do tipo FILE)
        printf("%s", linha); // Exibe cada linha do ficheiro
    }
    printf("\n");

    fclose(file);
    return NULL;
}

