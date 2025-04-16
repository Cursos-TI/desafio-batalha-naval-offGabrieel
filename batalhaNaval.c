#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
    int espacoLivre, espacoLivre2;
    
    char * tabuleiro [10][10] = {
        
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"}
        
    };
    
    // Posição navio horizontal 1
    
    if (tabuleiro[1][1] == "0" && tabuleiro[1][2] == "0" && tabuleiro[1][3] == "0") {
       
        tabuleiro[1][1] = "3";
        tabuleiro[1][2] = "3";
        tabuleiro[1][3] = "3";

    } else {
        printf("Posicionamento inválido!\n");
    }
    
    // Posição navio vertical 1
    
    if (tabuleiro[6][2] == "0" && tabuleiro[7][2] == "0" && tabuleiro[8][2] == "0") {
        
        tabuleiro[6][2] = "3";
        tabuleiro[7][2] = "3";
        tabuleiro[8][2] = "3";

    } else {
        printf("Posicionamento inválido!\n");
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.

    // Posição navio diagonal 1
    espacoLivre = 1;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][7 - i] != "0") {
            espacoLivre = 0;
            break;
        }
    }
    if (espacoLivre) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[i][8 - i] = "3";
        }
    } else {
        printf("Posicionamento inválido!\n");
    }

    // Posição navio diagonal 2
    
    espacoLivre2 = 1;
    for (int i = 4; i < 7; i++) {
        if (tabuleiro[i][9 + i] != "0") {
            espacoLivre2 = 0;
            break;
        }
    }
    if (espacoLivre2) {
        for (int i = 4; i < 7; i++) {
            tabuleiro[i][9 + i] = "3";
        }
    } else {
        printf("Posicionamento inválido!\n");
    }
    
    // Imprime o tabuleiro.
    
    printf("        ** TABULEIRO **\n");
    printf("   ");
    for (char letras = 'A'; letras <= 'J'; letras++) {
        printf(" %2c", letras);
    }
    printf("\n");
    
    for (int i = 0; i < 10; i++) {
        
        printf("%2d ", i + 1);
        
        for (int j = 0; j < 10; j++) {
            printf(" ");
            printf(" %s", tabuleiro[i][j]);
        }
        printf("\n");
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

    return 0;
}
