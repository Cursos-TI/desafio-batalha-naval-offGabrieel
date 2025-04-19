#include <stdio.h>

    // Desafio Batalha Naval - MateCheck
    // Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
    
    // Define quantidade de linhas e colunas da matriz (tabuleiro).
    
#define LINHAS 10
#define COLUNAS 10

    // Matriz que define a aplicação da habilidade em formato de cone.

void aplicarCone(int matriz[LINHAS][COLUNAS], int linha, int coluna) {
    int forma[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };
    
    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < 5; j++) {
            int lin = linha + i;
            int col = coluna + j - 2;
            
    // Verifica a área afetada pela habilidade cone.        
            
            if (lin >= 0 && lin < LINHAS && col >= 0 && col < COLUNAS && forma[i][j] == 1) {
                if (matriz[lin][col] == 3) {
                    matriz[lin][col] = 5;
                } else if (matriz[lin][col] == 0) {
                    matriz[lin][col] = 1;
                }
            }
        }
    }
}
    
    // Matriz que define a aplicação da habilidade em formato de cruz.

void aplicarCruz(int matriz[LINHAS][COLUNAS], int linha, int coluna) {
    int forma[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int lin = linha + i - 1;
            int col = coluna + j - 2;
            
    // Verifica a área afetada pela habilidade cruz.
            
            if (lin >= 0 && lin < LINHAS && col >= 0 && col < COLUNAS && forma[i][j] == 1) {
                if (matriz[lin][col] == 3) {
                    matriz[lin][col] = 5;
                } else if (matriz[lin][col] == 0) {
                    matriz[lin][col] = 1;
                }
            }
        }
    }
}

    // Matriz que define a aplicação da habilidade em formato de octaedro.

void aplicarOctaedro(int matriz[LINHAS][COLUNAS], int linha, int coluna) {
    int forma[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int lin = linha + i - 1;
            int col = coluna + j - 2;
            
    // Verifica a área afetada pela habilidade octaedro.
            
            if (lin >= 0 && lin < LINHAS && col >= 0 && col < COLUNAS && forma[i][j] == 1) {
                if (matriz[lin][col] == 3) {
                    matriz[lin][col] = 5;
                } else if (matriz[lin][col] == 0) {
                    matriz[lin][col] = 1;
                }
            }
        }
    }
}


int main() {
    
    // Inicializa a matriz do tabuleiro = 0.
    
    int matriz[LINHAS][COLUNAS];
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = 0;
        }
    }
    
    // Posiciona e verica a sobreposição do navio horizontal.

    if (matriz[5][5] == 0 && matriz[5][6] == 0 && matriz[5][7] == 0) {
        matriz[5][5] = 3;
        matriz[5][6] = 3;
        matriz[5][7] = 3;
    } else {
        printf("Posicionamento horizontal inválido!\n");
    }

    // Posiciona e verica a sobreposição do navio vertical.
    
    if (matriz[6][2] == 0 && matriz[7][2] == 0 && matriz[8][2] == 0) {
        matriz[6][2] = 3;
        matriz[7][2] = 3;
        matriz[8][2] = 3;
    } else {
        printf("Posicionamento vertical inválido!\n");
    }

    // Posiciona e verica a sobreposição do navio diagonal 1.

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

    // Posiciona e verica a sobreposição do navio diagonal 2.

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

    // Imprime o tabuleiro com o posicionamento dos návios. (posicionamentos definidos pelo código).

    int escolha;
    
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
    printf("\n");
    
    // Menu de interação parar selecionar habilidade que deseja visualizar no tabuleiro (ponto de habilidade definido pelo código).
    
    printf("Escolha um poder para visualizar no tabuleiro:\n");
    printf("1 - Cone\n");
    printf("2 - Cruz\n");
    printf("3 - Octaedro\n");
    printf("Digite uma opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: 
            int linha = 4, coluna = 6;
            aplicarCone(matriz, linha, coluna);
            
            break;
        case 2:
            
            int linha2 = 7, coluna2 = 2;
            aplicarCruz(matriz, linha2, coluna2);
            
            break;
        case 3:
            
            int linha3 = 2, coluna3 = 1;
            aplicarOctaedro(matriz, linha3, coluna3);
            
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    // Imprime o tabuleiro com a habilidade aplicada apresentando a área afetada pela habilidade.

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
