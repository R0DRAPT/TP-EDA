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
    #pragma region Declaração_Variaveis
    // Ponteiros para listas ligadas de antenas
    Antenas* listaAntenas = NULL; // Lista principal de antenas.
    ListaEfeitoNefasto* listaNefasto = NULL; //Lista principal do efeito nefasto
    Antenas* ListaAntenasAux = NULL; // Lista auxiliar
    #pragma endregion
    
    #pragma region Lista_mapaAntena.txt
    // Lista o mapa das antenas disponíveis
    printf("\n");
    ListarMapaAntenas("Ficheiros/mapaAntenas.txt");
    #pragma endregion

    #pragma region Carrega_Antenas_Do_mapaAntena
    // Carrega as antenas a partir de um ficheiro de texto
    ListaAntenasAux = CarregarMapaAntenas("Ficheiros/mapaAntenas.txt");
    if (ListaAntenasAux == NULL) {
        return 1; // Retorna 1 em caso de erro.
    }
    #pragma endregion

    #pragma region Listar_Antenas_Carregadas
    // Lista as antenas carregadas do ficheiro
    printf("\nAntenas encontradas no mapa:\n");
    ListarAntenas(ListaAntenasAux);
    printf("\n");
    #pragma endregion

    #pragma region Cria_&_Insere_Antena
    // Criação e inserção de antenas no início da lista principal
    ListaAntenasAux = InserirAntenaInicio(ListaAntenasAux, 'A', 1, 1);
    ListaAntenasAux = InserirAntenaInicio(ListaAntenasAux, 'A', 3, 2);

    // Criação e inserção de antenas no fim da lista principal
    ListaAntenasAux = InserirAntenaFim(ListaAntenasAux, 'C', 7, 7);

    // Criação e inserção de antenas na lista principal ordenadamente
    ListaAntenasAux = InserirAntenasOrdenado(ListaAntenasAux, 'J', 6, 6);

    // Mostra a lista ligada das antenas
    MostrarLista(ListaAntenasAux);
    printf("\n");
    #pragma endregion

    #pragma region Modifica_Antena
    //Modifica uma antena criada previamente, e lista novamente, mas modificado
    ListaAntenasAux = ModificarAntena(ListaAntenasAux, 1, 1, 'H', 2, 2);
    #pragma endregion
    
    #pragma region Mostrar_Listas
    // Mostra a lista ligada das antenas
    MostrarListaModificada(ListaAntenasAux);
    printf("\n");
    #pragma endregion

    #pragma region Remover_Antena
    // Exemplo de remoção de antena
    ListaAntenasAux = RemoverAntena(ListaAntenasAux, 7, 7);
    #pragma endregion

    #pragma region Calcular_Efeito_Nefasto
    // Chamada da função para calcular e apresentar os efeitos nefastos
    printf("\nEfeito nefasto calculado\n");
    EfeitoNefasto(listaAntenas, "Ficheiros/mapaAntenas.txt", 100, 100);
    printf("\n");
    #pragma endregion
   
    #pragma region Listar_Efeito_Nefasto
    // Lista o mapa das antenas com o efeito nefasto
    ListarMapaAntenasComNefasto("Ficheiros/mapaAntenasComNefasto.txt");

    // Lista o efeito nefasto guardado na lista ligada
    listaNefasto = ListarNefasto("Ficheiros/mapaAntenasComNefasto.txt");
    #pragma endregion

    #pragma region Listagem_Tabular
    //Listagem de forma tabular na consola das antenas e localizações com efeito nefasto.
    ListagemTabular(ListaAntenasAux, listaNefasto);

    #pragma endregion

    #pragma region Coloca_ListaAntena_Ficheiro_Bin
    //Cria um ficheiro bin com a lista ligada "Antena" 
    ImprimirListaFicheiro(ListaAntenasAux, "Ficheiros/Bin_mapaAntena");
    #pragma endregion

    #pragma region Imprimir_ListaAntena_Ficheiro_Bin
    //Imprime o ficheiro binario da lista ligada
    ListaFicheiroBin(ListaAntenasAux, "Ficheiros/Bin_mapaAntena");
    printf("\n");
    #pragma endregion

    #pragma region Limpar_Memoria
    // Liberta a memória alocada
    LimparMemoria(listaAntenas);
    #pragma endregion

    return 0; // Retorna 0 em caso de sucesso.
 }
 