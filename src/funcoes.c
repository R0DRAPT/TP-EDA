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
#include <string.h>
#include "funcoes.h"

/**
 * @brief Lê o ficheiro "mapaAntenas.txt" e imprime o seu conteúdo no terminal.
 * 
 * A função abre o ficheiro localizado na pasta "Ficheiros" e exibe as informações
 * armazenadas nele.
 * 
 * @return Retorna NULL pois não altera a lista ligada, apenas exibe os dados.
 */
Antenas* ListarMapaAntenas(const char *nomeFicheiro, int tamLinha) {     
    FILE *file = fopen(nomeFicheiro, "r");

    // Verifica se o ficheiro foi aberto com sucesso
    if (file == NULL) {
        return NULL;
    }

    char linha[tamLinha]; // Buffer para armazenar temporariamente cada linha do ficheiro

    // Lê e imprime cada linha do ficheiro
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }

    printf("\n");
    fclose(file); // Fecha o ficheiro após a leitura
    return NULL; // Retorna NULL, pois não há alteração na lista
}

/**
 * @brief Cria uma nova antena e insere-a no inicio da lista ligada.
 * 
 * @param inicio Ponteiro para o início da lista ligada de antenas.
 * @param freq Frequência da nova antena.
 * @param x Coordenada X da nova antena.
 * @param y Coordenada Y da nova antena.
 * @return Antenas* Retorna o ponteiro para o início da lista ligada. 
 */
Antenas* InserirAntenaInicio(Antenas* inicio, char freq, int x, int y) {

    // Verifica se já existe uma antena com as mesmas coordenadas
    Antenas* atual = inicio;
    while (atual != NULL) {
        if (atual->x == x && atual->y == y) {
            return inicio; //Retorna inicio quando ja existe uma antena naquelas coordenadas
        }
        atual = atual->prox;
    }

    // Aloca memória para uma nova antena
    Antenas* nova = (Antenas*)malloc(sizeof(Antenas));
    if (nova == NULL) {
        return inicio; // Retorna a lista original se a alocação falhar
    }
    
    // Inicializa os valores da antena
    nova->x = x;
    nova->y = y;
    nova->freq = freq;
    
    // Faz a nova antena apontar para o antigo primeiro nó da lista
    nova->prox = inicio;

    // Retorna a nova antena como o início da lista
    return nova;
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
Antenas* InserirAntenaFim(Antenas* inicio, char freq, int x, int y) {

    // Verifica se já existe uma antena com as mesmas coordenadas
    Antenas* atual = inicio;
    while (atual != NULL) {
        if (atual->x == x && atual->y == y) {
            return inicio; //Retorna inicio quando ja existe uma antena naquelas coordenadas
        }
        atual = atual->prox;
    }

    // Aloca memória para uma nova antena
    Antenas* nova = (Antenas*)malloc(sizeof(Antenas));
    if (nova == NULL) {
        return inicio; // Retorna inicio se der erro
    }

    // Inicializa os valores da antena
    nova->x = x; //
    nova->y = y;
    nova->freq = freq;
    nova->prox = NULL; // Como vai ser inserida no final, o próximo vai ser NULL

    // Se a lista estiver vazia, a nova antena será a primeira
    if (inicio == NULL) {
        return nova;
    }

    // Percorre a lista até encontrar o último elemento
    atual = inicio;
    while (atual->prox != NULL) { // "atual" ira percorrer a lista até que o proximo seja NULL (Quando for NULL significa que chegou ao fim)
        atual = atual->prox; 
    }

    // Insere no final
    atual->prox = nova; //ultimo elemento da lista aponta para "nova" assim fica o novo último elemento

    return inicio;
}

/**
 * @brief percorre e imprime todos os elementos da lista ligada
 * 
 * @param inicio 
 */
void MostrarLista(Antenas* inicio) {
    Antenas* atual = inicio; // Começa pelo primeiro elemento

    // Se a lista estiver vazia
    if (atual == NULL) {
        return;
    }

    // Percorre a lista e imprime cada antena
    printf("Lista de Antenas:\n");
    while (atual != NULL) {
        printf("%c - (%d, %d)\n", atual->freq, atual->x, atual->y);
        atual = atual->prox; // Avança para o próximo elemento
    }
}

/**
 * @brief percorre e imprime todos os elementos da lista ligada após a modificação
 * 
 * @param inicio 
 */
void MostrarListaModificada(Antenas* inicio) {
    Antenas* atual = inicio; // Começa pelo primeiro elemento

    // Se a lista estiver vazia
    if (atual == NULL) {
        return;
    }

    // Percorre a lista e imprime cada antena
    printf("Lista de Antenas Modificada:\n");
    while (atual != NULL) {
        printf("%c - (%d, %d)\n", atual->freq, atual->x, atual->y);
        atual = atual->prox; // Avança para o próximo elemento
    }
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
        printf("%c - (%d, %d)\n", atual->freq, atual->x, atual->y);
        atual = atual->prox;
    }
}

/**
 * @brief Liberta a memória alocada para a lista ligada de antenas.
 * 
 * Esta função percorre toda a lista ligada e liberta a memória ocupada por cada node.
 * 
 * @param inicio Ponteiro para o início da lista ligada de antenas.
 */
void LimparMemoria(Antenas* inicio) {
    Antenas *atual = inicio;
    while (atual != NULL)
    {
        Antenas* aux = atual;  // Guarda o ponteiro para não o perder
        atual = atual->prox;   // Avança para o proximo
        free(aux);             // Liberta a memória guardada pelo malloc naquele node
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

    return inicio; //Quando nao encontrada / quando acabar de remover
}

/**
 * @brief Carrega as antenas do ficheiro "mapaAntenas.txt" para uma lista ligada.
 * 
 * Esta função lê um ficheiro de texto que contém o mapa das antenas, identificando
 * as antenas com base nos caracteres presentes. Cada antena é adicionada ao final
 * da lista ligada utilizando a função InserirAntenaFim().
 * 
 * @param filename Caminho para o ficheiro de texto.
 * @return Antenas* Retorna a lista de antenas encontradas no mapa.
 */
Antenas* CarregarMapaAntenas(const char *nomeFicheiro, int tamLinha) {
    FILE *fp = fopen(nomeFicheiro, "r");
    if (fp == NULL) {
        return NULL; //Erro ao abrir o ficheiro
    }

    Antenas* lista = NULL;
    char linha[tamLinha]; // Buffer para armazenar cada linha do ficheiro
    int x = 1; // X representa o numero da linha

    //Le cada linha do ficheiro
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        //Percorre a linha caracter por caracter
        for (int y = 0; linha[y] != '\0'; y++) {
            char c = linha[y];
            // Se não for '.' e for um caractere visível (e não '\n'), considere antena
            if (c != '.' && c >= 33 && c != '\n') {
                // Agora, X = índice da linha, Y = índice da coluna
                lista = InserirAntenaFim(lista, c, x, y); //Adiciona a antena a lista
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
 * A função abre o ficheiro localizado na pasta "Ficheiros" e exibe as informações
 * armazenadas nele.
 * 
 * @return Retorna NULL pois não altera a lista ligada, apenas exibe os dados.
 */
Antenas* ListarMapaAntenasComNefasto(const char *nomeFicheiro, int tamLinha) {
    FILE *file = fopen(nomeFicheiro, "r");

    // Verifica se o ficheiro foi aberto com sucesso
    if (file == NULL) {
        return NULL;
    }

    char linha[tamLinha]; // Buffer para armazenar temporariamente cada linha do ficheiro

    // Lê e imprime cada linha do ficheiro
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }

    printf("\n");
    fclose(file); // Fecha o ficheiro após a leitura
    return NULL; // Retorna NULL, pois não há alteração na lista
}

/**
 * @brief Calcula o efeito nefasto causado por antenas com a mesma frequência.
 * 
 * Esta função percorre a lista de antenas e identifica pares que possuem a mesma
 * frequência. Para cada par, calcula a posição onde ocorre um efeito nefasto e
 * marca essas posições com '#' num novo ficheiro "mapaAntenasComNefasto.txt".
 * 
 * @param lista Ponteiro para o início da lista ligada de antenas.
 */
void EfeitoNefasto(Antenas* inicio, const char *nomeFicheiro, int tamLinha, int mapaX, int mapaY) {
    if (inicio == NULL) {
        return;
    }
    
    // Carregar o mapa do ficheiro para uma matriz
    FILE *fp = fopen(nomeFicheiro, "r");
    if (fp == NULL) {
        return; // Erro a abrir o ficheiro
    }
    
    char mapa[mapaX][mapaY]; // Matriz para armazenar o mapa das antenas
    int linhas = 1, colunas = 1; // Contadores para o número de linhas e colunas
    char linha[tamLinha]; // Buffer temporário para leitura de cada linha
    
    // Lê o ficheiro linha por linha e armazena na matriz "mapa"
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        strcpy(mapa[linhas], linha); // Copia a linha lida para a matriz
        colunas = strlen(linha); // Atualiza o número de colunas
        linhas++; // Incrementa o número de linhas
    }
    fclose(fp); // Fecha o ficheiro após a leitura
    
    // Percorre a lista de antenas para comparar cada antena com as restantes
    Antenas* a1 = inicio;
    while (a1 != NULL) {
        Antenas* a2 = a1->prox;
        while (a2 != NULL) {
            // Se ambas as antenas têm a mesma frequência, calcula o efeito nefasto
            if (a1->freq == a2->freq) {
                // Cálculo das coordenadas afetadas pelo efeito nefasto
                int x_nefasto1 = a1->x + (a1->x - a2->x);
                int y_nefasto1 = a1->y + (a1->y - a2->y);
                int x_nefasto2 = a2->x + (a2->x - a1->x);
                int y_nefasto2 = a2->y + (a2->y - a1->y);

                // Atualiza o mapa com '#' para indicar o efeito nefasto, se o local não contiver uma antena
                if (x_nefasto1 >= 0 && x_nefasto1 < linhas && y_nefasto1 >= 0 && y_nefasto1 < colunas) {
                    if (mapa[x_nefasto1][y_nefasto1] != '#' && mapa[x_nefasto1][y_nefasto1] != '.') {
                    }
                    mapa[x_nefasto1][y_nefasto1] = '#';
                }

                if (x_nefasto2 >= 0 && x_nefasto2 < linhas && y_nefasto2 >= 0 && y_nefasto2 < colunas) {
                    if (mapa[x_nefasto2][y_nefasto2] != '#' && mapa[x_nefasto2][y_nefasto2] != '.') {
                        printf("ATENCAO: A antena '%c' situada em (%d, %d) foi afetada pelo efeito nefasto\n", mapa[x_nefasto2][y_nefasto2], x_nefasto2, y_nefasto2);
                    }
                    mapa[x_nefasto2][y_nefasto2] = '#';
                }
            }
            a2 = a2->prox;
        }
        a1 = a1->prox;
    }
    
    // Abre um novo ficheiro para salvar o mapa atualizado com os efeitos nefastos
    fp = fopen("Ficheiros/mapaAntenasComNefasto.txt", "w");
    if (fp == NULL) {
        return; // Se não conseguir abrir o ficheiro, termina a função
    }
    
    // Escreve a matriz "mapa" no ficheiro atualizado
    for (int i = 0; i < linhas; i++) {
        fprintf(fp, "%s", mapa[i]);
    }
    fclose(fp); // Fecha o ficheiro após a gravação
}

/**
 * @brief Adiciona os efeitos nefastos à lista ligada e os imprime no terminal.
 * 
 * Esta função percorre a matriz do mapa atualizado "mapaAntenasComNefasto.txt",
 * identifica os pontos onde há efeitos nefastos ('#') e adiciona essas coordenadas
 * a uma lista ligada. Depois, imprime os efeitos nefastos encontrados.
 * 
 * @return ListaEfeitoNefasto* Retorna o ponteiro para o início da lista de efeitos nefastos.
 */
ListaEfeitoNefasto* ListarNefasto(const char *nomeFicheiro, int tamLinha) {
    FILE *fp = fopen(nomeFicheiro, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro de efeitos nefastos.\n");
        return NULL;
    }
    
    ListaEfeitoNefasto* lista = NULL;
    ListaEfeitoNefasto* ultimo = NULL;
    char linha[tamLinha];
    int x = 1;
    
    // Lê o ficheiro linha por linha
    while (fgets(linha, sizeof(linha), fp) != NULL) {
        for (int y = 0; linha[y] != '\0'; y++) {
            if (linha[y] == '#') {
                // Criar novo node para a lista de efeitos nefastos
                ListaEfeitoNefasto* novo = (ListaEfeitoNefasto*)malloc(sizeof(ListaEfeitoNefasto));
                if (novo == NULL) {
                    fclose(fp);
                    return lista; //Erro ao alocar memória para efeito nefasto
                }
                novo->x = x;
                novo->y = y;
                novo->prox = NULL;
                
                // Adiciona o novo node à lista ligada
                if (lista == NULL) {
                    lista = novo;
                } else {
                    ultimo->prox = novo;
                }
                ultimo = novo;
            }
        }
        x++;
    }
    fclose(fp);
    
    // Exibir a lista de efeitos nefastos
    ListaEfeitoNefasto* atual = lista;
    printf("\n\nEfeitos nefastos encontrados:\n\n");
    while (atual != NULL) {
        printf("Posição afetada: (%d, %d)\n", atual->x, atual->y);
        atual = atual->prox;
    }
    
    return lista;
}

/**
 * @brief Modifica as propriedades de uma antena existente na lista encadeada.
 * 
 * Esta função procura uma antena nas coordenadas fornecidas (x, y) e, se encontrada,
 * altera a sua frequência e move-a para novas coordenadas (novoX, novoY), garantindo
 * que não haja duplicação de antenas nessas novas coordenadas.
 * 
 * @param inicio Ponteiro para o início da lista encadeada de antenas.
 * @param x Coordenada X da antena a ser modificada.
 * @param y Coordenada Y da antena a ser modificada.
 * @param novaFreq Nova frequência a ser atribuída à antena.
 * @param novoX Nova coordenada X para onde a antena será movida.
 * @param novoY Nova coordenada Y para onde a antena será movida.
 * @return Antenas* Retorna o ponteiro para o início da lista (possivelmente modificada).
 * 
 * @note Se já existir uma antena nas novas coordenadas (novoX, novoY), a modificação não ocorre.
 * @note Caso a antena não seja encontrada, a lista mantém-se inalterada.
 */
Antenas* ModificarAntena(Antenas* inicio, int x, int y, char novaFreq, int novoX, int novoY) {
    // Verifica se a lista está vazia
    if (inicio == NULL) {
        return NULL;
    }

    Antenas* atual = inicio;

    // Percorre a lista para encontrar a antena nas coordenadas fornecidas
    while (atual != NULL) {
        if (atual->x == x && atual->y == y) {
            // Verifica se já existe uma antena nas novas coordenadas para evitar duplicação
            Antenas* aux = inicio;
            while (aux != NULL) {
                if (aux->x == novoX && aux->y == novoY) {
                    return inicio; // Mantém a lista sem alterações (Ocorre quando ja existe uma antena naquelas coordenadas)
                }
                aux = aux->prox;
            }

            // Modifica os valores da antena
            atual->freq = novaFreq;
            atual->x = novoX;
            atual->y = novoY;

            return inicio; // Retorna a lista atualizada
        }
        atual = atual->prox;
    }

    return inicio; // Retorna a lista original se a antena não for encontrada
}

/**
 * @brief Listagem de forma tabular na consola das antenas e localizações com efeito nefasto.
 * 
 * @param inicioAntenas Ponteiro para o início da lista de antenas.
 * @param inicioNefasto Ponteiro para o início da lista de efeito nefasto.
 */
void ListagemTabular(Antenas* inicioAntenas, ListaEfeitoNefasto* inicioNefasto) {
    printf("\n\nLista Antenas         Efeitos Nefastos\n");
    printf("--------------------- -------------------\n");
    printf("Freq    X    Y        | X    Y\n");

    // Iterar pela lista de antenas
    Antenas* atualAntena = inicioAntenas;
    ListaEfeitoNefasto* atualEfeito = inicioNefasto;
    while (atualAntena != NULL || atualEfeito != NULL) {
        // Imprimir informações da antena
        if (atualAntena != NULL) {
            printf(" %-6c %-4d %-4d     |", atualAntena->freq, atualAntena->x, atualAntena->y);
            atualAntena = atualAntena->prox;
        } else {
            // Caso uma lista termine antes, imprime espaços
            printf("                      |");
        }

        // Imprimir informações do efeito nefasto
        if (atualEfeito != NULL) {
            printf(" %-4d %-4d\n", atualEfeito->x, atualEfeito->y);
            atualEfeito = atualEfeito->prox;
        } else {
            // Caso uma lista termine antes, apenas salta a linha
            printf("\n");
        }
    }
}

/**
 * @brief Função para imprimir e gravar a lista ligada "Antenas" em um arquivo binário
 * 
 * Esta função percorre a lista ligada de antenas e grava os dados de cada
 * antena no arquivo binário especificado. O arquivo é gravado no formato
 * `AntenasBin`, sem o ponteiro `prox`.
 * 
 * @param inicio Ponteiro para o início da lista ligada de antenas.
 * @param nomeFicheiro Nome do arquivo binário onde os dados serão gravados.
 * 
 * @return Retorna 1 se a gravação for bem-sucedida, ou 0 em caso de erro.
 */
Antenas* ImprimirListaFicheiro(Antenas* inicio, const char* nomeFicheiro) {
    FILE* fp;

    // Verifica se a lista está vazia
    if (inicio == NULL) return 0;

    // Abre o arquivo binário para escrita
    if ((fp = fopen(nomeFicheiro, "wb")) == NULL) {
        return 0;
    }

    // Percorre a lista ligada e grava no arquivo
    Antenas* aux = inicio;
    AntenasBin auxElement;  // Estrutura auxiliar para gravar no arquivo

    while (aux != NULL) {
        // copia os dados da lista para a estrutura auxiliar
        auxElement.x = aux->x;
        auxElement.y = aux->y;
        auxElement.freq = aux->freq;
        // Grava a estrutura auxiliar no arquivo binário
        fwrite(&auxElement, sizeof(AntenasBin), 1, fp);

        // avança para o próximo nó da lista
        aux = aux->prox;
    }

    fclose(fp);

    return inicio;
}

/**
 * @brief Função que lê um arquivo binário e reconstrói uma lista ligada de antenas.
 * 
 * Esta função lê os dados de antenas de um arquivo binário e cria uma lista
 * ligada com os dados lidos. Cada antena lida do arquivo será inserida no final
 * da lista ligada.
 * 
 * @param inicio Ponteiro para o início da lista ligada. Inicialmente deve ser NULL.
 * @param nomeFicheiro Nome do arquivo binário a ser lido.
 * 
 * @return Retorna o ponteiro para o início da lista ligada reconstruída, ou NULL em caso de erro.
 */
void ListaFicheiroBin(Antenas* inicio, const char *nomeFicheiro) {
    FILE *fp = fopen(nomeFicheiro, "rb");
    if (fp == NULL) {
        return; //Erro ao abrir o ficheiro
    }

    // Verifica se a lista está vazia
    if (inicio == NULL) { fclose(fp); return; } //A lista está vazia
    
    AntenasBin auxAntena;
    printf("\nLista de Elementos no ficheiro: %s:\n", nomeFicheiro);
    while (fread(&auxAntena, sizeof(AntenasBin), 1, fp) == 1) {
        printf("%d - (%d, %d)\n", auxAntena.freq, auxAntena.x, auxAntena.y);
    }
    
    fclose(fp);
}
