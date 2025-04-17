#include <stdio.h>

    // Desafio Batalha Naval - MateCheck
    // Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

#define LINHAS 10
#define COLUNAS 10

int main() {
    
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
    int matriz[LINHAS][COLUNAS];
    
    // Inicializa a matriz do tabuleiro = 0.
    
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = 0;
        }
    }

    // Posição navio horizontal.
    
    if (matriz[5][5] == 0 && matriz[5][6] == 0 && matriz[5][7] == 0) {
        matriz[5][5] = 3;
        matriz[5][6] = 3;
        matriz[5][7] = 3;
    } else {
        printf("Posicionamento horizontal inválido!\n");
    }

    // Posição navio vertical.
    
    if (matriz[6][2] == 0 && matriz[7][2] == 0 && matriz[8][2] == 0) {
        matriz[6][2] = 3;
        matriz[7][2] = 3;
        matriz[8][2] = 3;
    } else {
        printf("Posicionamento vertical inválido!\n");
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.

    // Posição navio diagonal 1.
    
    int espacoLivre = 1;
    for (int i = 0; i < 3; i++) {
        if (matriz[i][7 - i] != 0) {
            espacoLivre = 0;
            break;
        }
    }
    if (espacoLivre) {
        for (int i = 0; i < 3; i++) {
            matriz[i][7 - i] = 3;
        }
    } else {
        printf("Posicionamento diagonal 1 inválido!\n");
    }

    // Posição navio diagonal 2.
    
    espacoLivre = 1;
    for (int i = 0; i < 3; i++) {
        if (matriz[1 + i][i] != 0) {
            espacoLivre = 0;
            break;
        }
    }
    if (espacoLivre) {
        for (int i = 0; i < 3; i++) {
            matriz[1 + i][i] = 3;
        }
    } else {
        printf("Posicionamento diagonal 2 inválido!\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    
    // Imprime o tabuleiro
    
    printf("\n        ** TABULEIRO **\n");
    printf("   ");
    for (char letras = 'A'; letras < 'A' + COLUNAS; letras++) {
        printf(" %2c", letras);
    }
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf("  %d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}