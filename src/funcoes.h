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
  * @param nomeFicheiro 
  * @return Antenas* 
  */
Antenas* ListarMapaAntenas(const char *nomeFicheiro);

/**
 * @brief Carrega as antenas do ficheiro (ex.: "mapaAntenas.txt") para uma lista ligada.
 * 
 * Percorre o ficheiro linha a linha, coluna a coluna; se encontrar um caractere visível
 * (diferente de '.' e de '\n'), insere na lista como antena.
 * 
 * @param nomeFicheiro Caminho para o ficheiro (ex.: "FicheirosTexto/mapaAntenas.txt").
 * @return Antenas* Retorna a lista de antenas lida do ficheiro.
 */
Antenas* CarregarMapaAntenas(const char *nomeFicheiro);

/**
 * @brief Cria uma nova antena e insere-a no fim da lista ligada.
 * 
 * @param inicio Ponteiro para o início da lista ligada.
 * @param freq Frequência da nova antena.
 * @param x Coordenada X da antena.
 * @param y Coordenada Y da antena.
 * @return Antenas* Retorna o ponteiro para o início da lista.
 */
Antenas* InserirAntenaFim(Antenas* inicio, char freq, int x, int y);

/**
 * @brief Cria uma nova antena e insere-a no inicio da lista ligada.
 * 
 * @param inicio Ponteiro para o início da lista ligada.
 * @param freq Frequência da nova antena.
 * @param x Coordenada X da antena.
 * @param y Coordenada Y da antena.
 * @return Antenas* Retorna o ponteiro para o início da lista.
 */
Antenas* InserirAntenaInicio(Antenas* inicio, char freq, int x, int y);

/**
 * @brief Insere ordenadamente na lista ligada
 * 
 * @param inicio 
 * @param freq 
 * @param x 
 * @param y 
 * @return Antenas* 
 */
Antenas* InserirAntenasOrdenado(Antenas* inicio, char freq, int x, int y);

/**
 * @brief Imprime no terminal a lista ligada das antenas
 * 
 */
void MostrarLista(Antenas* inicio);

/**
 * @brief Imprime no terminal a lista ligada das antenas apos modificação
 * 
 */
void MostrarListaModificada(Antenas* inicio);

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

 /**
  * @brief Calcula o efeito nefasto causado por antenas com a mesma frequência.
  * 
  * @param inicio Ponteiro para o início da lista ligada.
  * @param nomeFicheiro 
  * @param tamLinha 
  * @param mapaX 
  * @param mapaY 
  */
void EfeitoNefasto(Antenas* inicio, const char *nomeFicheiro, int mapaX, int mapaY);

 /**
  * @brief Lê o ficheiro "mapaAntenasComNefasto.txt" e imprime o seu conteúdo no terminal.
  * 
  * @param nomeFicheiro 
  * @param tamLinha
  * @return Antenas* 
  */
Antenas* ListarMapaAntenasComNefasto(const char *nomeFicheiro);

 /**
  * @brief Adiciona os efeitos nefastos à lista ligada e os imprime no terminal.
  * 
  * @param nomeFicheiro 
  * @param tamLinha 
  * @return ListaEfeitoNefasto* 
  */
ListaEfeitoNefasto* ListarNefasto(const char *nomeFicheiro);

/**
 * @brief Modifica uma antena na lista ligada
 * 
 */
Antenas* ModificarAntena(Antenas* inicio, int x, int y, char novaFreq, int novoX, int novoY);

/**
 * @brief Listagem de forma tabular na consola das antenas e localizações com efeito nefasto.
 * 
 * @param inicioAntenas 
 * @param inicioNefasto 
 */
void ListagemTabular(Antenas* inicioAntenas, ListaEfeitoNefasto* inicioNefasto);

/**
 * @brief Imprime a lista ligada "Antenas" num ficheiro binario
 * 
 * @param inicio 
 * @param nomeFicheiro 
 * @return Antenas* 
 */
Antenas* ImprimirListaFicheiro(Antenas* inicio, const char* nomeFicheiro);

/**
 * @brief Lista o ficheiro binario da lista ligada "Antenas"
 * 
 * @param inicio 
 * @param nomeFicheiro 
 */
void ListaFicheiroBin(Antenas* inicio, const char *nomeFicheiro);
#endif