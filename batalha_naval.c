#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main(){

    printf("Tabuleiro de Batalha Naval\n");
    printf("\n");
    // Tabuleiro:
    int tamanhoTabuleiro = 10;

    int tabuleiro[LINHAS][COLUNAS] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    // Navios:
    int tamanhoNavio = 3;

    // Início do navio horizontal
    int lin_ini_navH = 5;
    int col_ini_navH = 3;

    // Início do navio vertical
    int lin_ini_navV = 7;
    int col_ini_navV = 2;

    // Início do navio diagonal 1 (diagonal direita/baixo)
    int lin_ini_navD1 = 0;
    int col_ini_navD1 = 7;

    // Início do navio diagonal 2 (diagonal esquerda/cima (subtrai do inicio))
    int lin_ini_navD2 = 2;
    int col_ini_navD2 = 4;

    //                         Verificando sobreposições:

    // Horizontal x Vertical:
    for (int i = 0; i < tamanhoNavio; i++){
        int linha_H = lin_ini_navH;
        int coluna_H = col_ini_navH + i;

        for (int j = 0; j < tamanhoNavio; j++){
            int linha_V = lin_ini_navV + j;
            int coluna_V = col_ini_navV;

            if (linha_H == linha_V && coluna_H == coluna_V){
            printf("Houve sobreposição dos navios!\n");
            return 0; // Encerra o programa se houver sobreposição
            }
        }
    }

    // Horizontal x Diagonal 1:
    for (int i = 0; i < tamanhoNavio; i++){
        int linha_H = lin_ini_navH;
        int coluna_H = col_ini_navH + i;

        for (int j = 0; j < tamanhoNavio; j++){
            int linha_D1 = lin_ini_navD1 + j;
            int coluna_D1 = col_ini_navD1 + j;

            if (linha_H == linha_D1 && coluna_H == coluna_D1){
                printf("Houve sobreposição dos navios!\n");
                return 0; // Encerra o programa se houver sobreposição
            }
        }
    }

    // Horizontal x Diagonal 2:
    for (int i = 0; i < tamanhoNavio; i++){
        int linha_H = lin_ini_navH;
        int coluna_H = col_ini_navH + i;

        for (int j = 0; j < tamanhoNavio; j++){
            int linha_D2 = lin_ini_navD2 - j;
            int coluna_D2 = col_ini_navD2 - j;

            if (linha_H == linha_D2 && coluna_H == coluna_D2){
                printf("Houve sobreposição dos navios!\n");
                return 0; // Encerra o programa se houver sobreposição
            }
        }
    }

    // Vertical x Diagonal 1:
    for (int i = 0; i < tamanhoNavio; i++){
        int linha_V = lin_ini_navV + i;
        int coluna_V = col_ini_navV;

        for (int j = 0; j < tamanhoNavio; j++){
            int linha_D1 = lin_ini_navD1 + j;
            int coluna_D1 = col_ini_navD1 + j;

            if (linha_V == linha_D1 && coluna_V == coluna_D1){
                printf("Houve sobreposição dos navios!\n");
                return 0; // Encerra o programa se houver sobreposição
            }
        }
    }

    // Vertical x Diagonal 2:
    for (int i = 0; i < tamanhoNavio; i++){
        int linha_V = lin_ini_navV + i;
        int coluna_V = col_ini_navV ;

        for (int j = 0; j < tamanhoNavio; j++){
            int linha_D2 = lin_ini_navD2 - j;
            int coluna_D2 = col_ini_navD2 - j;

            if (linha_V == linha_D2 && coluna_V == coluna_D2){
                printf("Houve sobreposição dos navios!\n");
                return 0; // Encerra o programa se houver sobreposição
            }
        }
    }

    // Diagonal 1 x Diagonal 2:
    for (int i = 0; i < tamanhoNavio; i++){
        int lin_d1 = lin_ini_navD1 + i;
        int col_d1 = col_ini_navD1 + i;

        for (int j = 0; j < tamanhoNavio; j++){
            int lin_d2 = lin_ini_navD2 - j;
            int col_d2 = col_ini_navD2 - j;

            if (lin_d1 == lin_d2 && col_d1 == col_d2){
                printf("Houve sobreposição dos navios!\n");
                return 0; // Encerra o programa se houver sobreposição
            }
        }
    }

    // Preenchendo o navio Horizontal na matriz e testando limites do tabuleiro:
    for (int i = 0; i < tamanhoNavio; i++){
        if (lin_ini_navH >= 0 && lin_ini_navH < tamanhoTabuleiro &&
            (col_ini_navH + i) >= 0 && (col_ini_navH + i) < tamanhoTabuleiro){
                tabuleiro[lin_ini_navH][col_ini_navH + i] = 3;
            }else {
                printf("Navio posicionado fora do tabuleiro!\n");
                printf("\n");
                return 0;
            }
    }

    // Preenchendo o navio Vertical na matriz e testando limites do tabuleiro:
    for (int i = 0; i < tamanhoNavio; i++){
        if (lin_ini_navV >= 0 && lin_ini_navV < (tamanhoTabuleiro -2) && // Tamanho do tabuleiro calculado para garantir a correta execução
            (col_ini_navV + i) >= 0 && (col_ini_navV + i) < tamanhoTabuleiro){
                tabuleiro[lin_ini_navV + i][col_ini_navV] = 3;
            }else {
                printf("Navio posicionado fora do tabuleiro!\n");
                printf("\n");
                return 0;
            }
    }

    // Preenchendo o navio Diagonal 1 na matriz e testando limites do tabuleiro:
    for (int i = 0; i < tamanhoNavio; i++){
        if (lin_ini_navD1 >= 0 && lin_ini_navD1 < tamanhoTabuleiro &&
            (col_ini_navD1 + i) >= 0 && (col_ini_navD1 + i) < tamanhoTabuleiro){
                tabuleiro[lin_ini_navD1 + i][col_ini_navD1 + i] = 3;
            }else {
                printf("Navio posicionado fora do tabuleiro!\n");
                printf("\n");
                return 0;
            }
    }

    // Preenchendo o navio Diagonal 2 na matriz e testando limites do tabuleiro:
    for (int i = 0; i < tamanhoNavio; i++){
        if (lin_ini_navD2 >= 2 && lin_ini_navD2 < tamanhoTabuleiro &&
            (col_ini_navD2 - i) >= 2 && (col_ini_navD2 - i) < tamanhoTabuleiro){
                tabuleiro[lin_ini_navD2 - i][col_ini_navD2 - i] = 3;
            } else {
                printf("Navio posicionado fora do tabuleiro!\n");
                printf("\n");
                return 0;
            }
    }

    // Imprimindo o Tabuleiro:
    for (int x = 0; x < tamanhoTabuleiro; x++){
        for (int y = 0; y < tamanhoTabuleiro; y++){
            printf("%d ", tabuleiro[x][y]);
        }
        printf("\n");
    }


    printf("\n"); // Quebra de linha para melhorar a visualização

    return 0;
}