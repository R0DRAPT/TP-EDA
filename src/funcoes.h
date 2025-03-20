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
 * @brief Cabeçalho da função "ListarMapaAntenas"
 * 
 * \alias ListarMapaAntenas
 * 
 * @return Antenas* 
 */
Antenas* ListarMapaAntenas();

Antenas* CriarAntenaFim(Antenas* inicio, char freq, int x, int y);

void ListarAntenas(Antenas* inicio);


#endif
