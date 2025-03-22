/**
 * @file main.c
 * @author Rodrigo Miranda (a31509@alunos.ipca.pt)
 * @brief Ficheiro principal do programa para gerir antenas.
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "funcoes.h"
 
 /**
  * @brief Função principal do programa.
  * 
  */
 int main() {
    // Ponteiros para listas ligadas de antenas
    Antenas* listaAntenas = NULL; // Lista principal de antenas.

    // Lista o mapa das antenas disponíveis
    printf("\n");
    ListarMapaAntenas();

    // Criação e inserção de antenas na lista principal
    listaAntenas = CriarAntenaFim(listaAntenas, 'A', 1, 1);
    listaAntenas = CriarAntenaFim(listaAntenas, 'A', 3, 2);
    listaAntenas = CriarAntenaFim(listaAntenas, 'O', 5, 1);

    // Lista as antenas criadas manualmente
    printf("\nAntenas criadas manualmente:\n");
    ListarAntenas(listaAntenas);

    // Carrega as antenas a partir de um ficheiro de texto
    listaAntenas = CarregarMapaAntenas("FicheirosTexto/mapaAntenas.txt");
    if (listaAntenas == NULL) {
        return 1; // Retorna 1 em caso de erro.
    }

    // Lista as antenas carregadas do ficheiro
    printf("\nAntenas encontradas no mapa:\n");
    ListarAntenas(listaAntenas);
    printf("\n");

    // Exemplo de remoção de antena
    // listaAntenas = RemoverAntena(listaAntenas, 1, 1);

    // Chamada da função para calcular e apresentar os efeitos nefastos
    EfeitoNefasto(listaAntenas);
    printf("\n");
   
    //Lista o mapa das antenas com o efeito nefasto
    ListarMapaAntenasComNefasto();

    // Liberta a memória alocada
    LimparMemoria(listaAntenas);

    return 0; // Retorna 0 em caso de sucesso.
 }
 