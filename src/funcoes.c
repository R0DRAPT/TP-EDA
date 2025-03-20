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

/**
 * @brief Cria uma nova antena e insere-a no fim da lista ligada.
 * 
 * Esta função aloca memória para uma nova antena, define os seus atributos
 * e adiciona-a ao final da lista ligada, garantindo a ordem FIFO (First In, First Out).
 * 
 * @param inicio Ponteiro para o início da lista ligada de antenas.
 * @param freq Frequência da nova antena.
 * @param x Coordenada X da nova antena.
 * @param y Coordenada Y da nova antena.
 * @return Antenas* Retorna o ponteiro para o início da lista ligada.
 */
Antenas* CriarAntenaFim(Antenas* inicio, char freq, int x, int y) {
    // Guarda memória para uma nova antena
    Antenas* nova = (Antenas*)malloc(sizeof(Antenas));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        return inicio;
    }

    // Inicializa os valores da antena
    nova->x = x;
    nova->y = y;
    nova->freq = freq;
    nova->prox = NULL; // Como vai ser inserida no final, o próximo vai ser NULL

    printf("\nAntena criada: Frequência: %c; X: %d; Y: %d\n\n", nova->freq, nova->x, nova->y);

    // Se a lista estiver vazia, a nova antena será a primeira
    if (inicio == NULL) {
        return nova;
    }

    // Percorre a lista até encontrar o último elemento
    Antenas* atual = inicio;
    while (atual->prox != NULL) { //a variavel atual ira percorrer a lista até que o proximo seja NULL == Chegou ao fim
        atual = atual->prox; 
    }

    // Insere no final
    atual->prox = nova;

    return inicio;
}

void ListarAntenas(Antenas* inicio) {
    Antenas* atual = inicio;
    while (atual != NULL) {
        printf("Antena: Frequência %c | Posição (%d, %d)\n", atual->freq, atual->x, atual->y);
        atual = atual->prox;
    }
}
