/**
 * @file funcoes.h
 * @author Rodrigo Miranda (a31509@alunos.ipca.pt)
 * @brief Ficheiro de cabeçalho onde são declaradas as assinaturas das funções implementadas em funcoes.c
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "dados.h"

#ifndef FUNCOES_H //Include Guard - evita inclusões múltiplas do mesmo cabeçalho durante a compilação.
#define FUNCOES_H

/**
 * @brief Lê o ficheiro "mapaAntenas.txt" e imprime o seu conteúdo no terminal.
 * 
 * @return Antenas* Retorna NULL, pois não altera a lista ligada.
 */
Antenas* ListarMapaAntenas();

/**
 * @brief Carrega as antenas do ficheiro (ex.: "mapaAntenas.txt") para uma lista ligada.
 * 
 * Percorre o ficheiro linha a linha, coluna a coluna; se encontrar um caractere visível
 * (diferente de '.' e de '\n'), insere na lista como antena.
 * 
 * @param filename Caminho para o ficheiro (ex.: "FicheirosTexto/mapaAntenas.txt").
 * @return Antenas* Retorna a lista de antenas lida do ficheiro.
 */
Antenas* CarregarMapaAntenas(const char* filename);

/**
 * @brief Cria uma nova antena e insere-a no fim da lista ligada.
 * 
 * @param inicio Ponteiro para o início da lista ligada.
 * @param freq Frequência da nova antena.
 * @param x Coordenada X da antena.
 * @param y Coordenada Y da antena.
 * @return Antenas* Retorna o ponteiro para o início da lista.
 */
Antenas* CriarAntenaFim(Antenas* inicio, char freq, int x, int y);

/**
 * @brief Lista todas as antenas na lista ligada.
 * 
 * @param inicio Ponteiro para o início da lista ligada.
 */
void ListarAntenas(Antenas* inicio);

/**
 * @brief Liberta a memória alocada para a lista ligada de antenas.
 * 
 * @param inicio Ponteiro para o início da lista ligada.
 */
void LimparMemoria(Antenas* inicio);

/**
 * @brief Remove uma antena da lista ligada com base nas coordenadas fornecidas.
 * 
 * @param inicio Ponteiro para o início da lista ligada.
 * @param x Ponteiro para a coordenada X da antena a ser removida.
 * @param y Ponteiro para a coordenada Y da antena a ser removida.
 * @return Antenas* Retorna o ponteiro para o início da lista após a remoção.
 */
Antenas* RemoverAntena(Antenas* inicio, int x, int y);


void EfeitoNefasto(Antenas* inicio);

/**
 * @brief Lê o ficheiro "mapaAntenasComNefasto.txt" e imprime o seu conteúdo no terminal.
 * 
 * @return Antenas* Retorna NULL, pois não altera a lista ligada.
 */
Antenas* ListarMapaAntenasComNefasto();
#endif
 