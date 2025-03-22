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

    // Verifica se o ficheiro foi aberto com sucesso
    if (file == NULL) {
        return NULL;
    }

    char linha[100]; // Buffer para armazenar temporariamente cada linha do ficheiro

    // Lê e imprime cada linha do ficheiro
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }

    printf("\n");
    fclose(file); // Fecha o ficheiro após a leitura
    return NULL; // Retorna NULL, pois não há alteração na lista
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
    // Aloca memória para uma nova antena
    Antenas* nova = (Antenas*)malloc(sizeof(Antenas));
    if (nova == NULL) {
        return inicio; // Retorna inicio se der erro
    }

    // Inicializa os valores da antena
    nova->x = x;
    nova->y = y;
    nova->freq = freq;
    nova->prox = NULL; // Como vai ser inserida no final, o próximo vai ser NULL

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

/**
 * @brief Lista todas as antenas da lista ligada.
 * 
 * A função percorre a lista ligada e imprime no terminal as informações de cada antena.
 * 
 * @param inicio Ponteiro para o início da lista ligada de antenas.
 */
void ListarAntenas(Antenas* inicio) {
    Antenas* atual = inicio;
    while (atual != NULL) {
        printf("Antena: Frequência %c | Posição (%d, %d)\n", atual->freq, atual->x, atual->y);
        atual = atual->prox;
    }
}

/**
 * @brief Liberta a memória alocada para a lista ligada de antenas.
 * 
 * Esta função percorre toda a lista ligada e liberta a memória ocupada por cada nó.
 * 
 * @param inicio Ponteiro para o início da lista ligada de antenas.
 */
void LimparMemoria(Antenas* inicio) {
    Antenas *atual = inicio;
    while (atual != NULL)
    {
        Antenas* temp = atual;  // Guarda o ponteiro para não o perder
        atual = atual->prox;    // Avança para o proximo
        free(temp);             // Liberta a memória guardada pelo malloc naquela nó
    }
}

/**
 * @brief Remove uma antena da lista ligada.
 * 
 * Esta função remove uma antena específica da lista ligada com base nas coordenadas fornecidas.
 * 
 * @param inicio Ponteiro para o início da lista ligada de antenas.
 * @param x Coordenada X da antena a remover.
 * @param y Coordenada Y da antena a remover.
 * @return Antenas* Retorna o ponteiro para o início da lista ligada após a remoção.
 */
Antenas* RemoverAntena(Antenas* inicio, int x, int y) {
    //Verifica se a lista esta vazia
    if (inicio == NULL) {
        return NULL; // Se estiver vazia retorna NULL
    }

    //Pede ao utilizador as coordenandas da antena que deseja remover
    //printf("Insira as coordenadas da antena a remover (x y): ");
    //scanf("%d %d", &x, &y);

    Antenas *atual = inicio;
    Antenas *anterior = NULL;

    // Percorre a lista para encontrar a antena
    while (atual != NULL) {
        if (atual->x == x && atual->y == y) {
            // Antena encontrada
            if (anterior == NULL) {
                // A antena a remover é a primeira da lista
                inicio = atual->prox;
            } else {
                // A antena a remover está no meio ou fim da lista
                anterior->prox = atual->prox;
            }
            return inicio; // Antena removida com sucesso
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Antena não encontrada.\n");
    return inicio;
}

/**
 * @brief Carrega as antenas do ficheiro "mapaAntenas.txt" para uma lista ligada.
 * 
 * Esta função lê um ficheiro de texto que contém o mapa das antenas, identificando
 * as antenas com base nos caracteres presentes. Cada antena é adicionada ao final
 * da lista ligada utilizando a função CriarAntenaFim().
 * 
 * @param filename Caminho para o ficheiro de texto.
 * @return Antenas* Retorna a lista de antenas encontradas no mapa.
 */
Antenas* CarregarMapaAntenas(const char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL; //Erro ao abrir o ficheiro
    }

    Antenas* lista = NULL;
    char linha[256]; // Buffer para armazenar cada linha do ficheiro
    int x = 1; // X representa o numero da linha

    //Le cada linha do ficheiro
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        //Percorre a linha caracter por caracter
        for (int y = 0; linha[y] != '\0'; y++) {
            char c = linha[y];
            // Se não for '.' e for um caractere visível (e não '\n'), considere antena
            if (c != '.' && c >= 33 && c != '\n') {
                // Agora, X = índice da linha, Y = índice da coluna
                lista = CriarAntenaFim(lista, c, x, y); //Adiciona a antena a lista
            }
        }
        x++; // incrementa a linha apos a leitura completa
    }

    fclose(fp); //Fecha o ficheiro apos a leitura
    return lista; //retorna a lista ligada de antenas
}


/**
 * @brief Lê o ficheiro "mapaAntenasComNefasto.txt" e imprime o seu conteúdo no terminal.
 * 
 * A função abre o ficheiro localizado na pasta "FicheirosTexto" e exibe as informações
 * armazenadas nele.
 * 
 * @return Retorna NULL pois não altera a lista ligada, apenas exibe os dados.
 */
Antenas* ListarMapaAntenasComNefasto() {
    FILE *file = fopen("FicheirosTexto/mapaAntenasComNefasto.txt", "r");

    // Verifica se o ficheiro foi aberto com sucesso
    if (file == NULL) {
        return NULL;
    }

    char linha[100]; // Buffer para armazenar temporariamente cada linha do ficheiro

    // Lê e imprime cada linha do ficheiro
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }

    printf("\n");
    fclose(file); // Fecha o ficheiro após a leitura
    return NULL; // Retorna NULL, pois não há alteração na lista
}

void EfeitoNefasto(Antenas* lista) {
    if (lista == NULL) {
        return;
    }
    
    // Carregar o mapa do ficheiro para uma matriz
    FILE *fp = fopen("FicheirosTexto/mapaAntenas.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro do mapa.\n");
        return;
    }
    
    char mapa[100][100];
    int linhas = 1, colunas = 1;
    char linha[100];
    
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        strcpy(mapa[linhas], linha);
        colunas = strlen(linha);
        linhas++;
    }
    fclose(fp);
    
    Antenas* a1 = lista;
    while (a1 != NULL) {
        Antenas* a2 = a1->prox;
        while (a2 != NULL) {
            if (a1->freq == a2->freq) {
                // Cálculo do efeito nefasto da primeira antena
                int x_nefasto1 = a1->x + (a1->x - a2->x);
                int y_nefasto1 = a1->y + (a1->y - a2->y);

                // Cálculo do efeito nefasto da segunda antena
                int x_nefasto2 = a2->x + (a2->x - a1->x);
                int y_nefasto2 = a2->y + (a2->y - a1->y);

                printf("Efeito nefasto para antena (%c) em (%d, %d): (%d, %d)\n", a1->freq, a1->x, a1->y, x_nefasto1, y_nefasto1);
                printf("Efeito nefasto para antena (%c) em (%d, %d): (%d, %d)\n", a2->freq, a2->x, a2->y, x_nefasto2, y_nefasto2);

                // Atualizar o mapa com '#'
                if (x_nefasto1 >= 0 && x_nefasto1 < linhas && y_nefasto1 >= 0 && y_nefasto1 < colunas)
                    mapa[x_nefasto1][y_nefasto1] = '#';
                if (x_nefasto2 >= 0 && x_nefasto2 < linhas && y_nefasto2 >= 0 && y_nefasto2 < colunas)
                    mapa[x_nefasto2][y_nefasto2] = '#';
            }
            a2 = a2->prox;
        }
        a1 = a1->prox;
    }
    
    // Criar um novo ficheiro para salvar o mapa atualizado
    fp = fopen("FicheirosTexto/mapaAntenasComNefasto.txt", "w");
    if (fp == NULL) {
        return;
    }
    
    for (int i = 0; i < linhas; i++) {
        fprintf(fp, "%s", mapa[i]);
    }
    fclose(fp);
}