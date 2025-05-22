#include <stdio.h>

int main(){

    printf("Tabuleiro de Batalha Naval\n");
    printf("\n");
    // Tabuleiro:
    int tamanhoTabuleiro = 10;

    int tabuleiro[10][10] = {
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
    int lin_ini_navV = 1;
    int col_ini_navV = 2;

    // Verificando sobreposições:
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

    // Preenchendo o navio Horizontal na matriz e testando limites do tabuleiro:
    for (int i = 0; i < tamanhoNavio; i++){
        if (lin_ini_navH >= 0 && lin_ini_navH < tamanhoTabuleiro &&
            (col_ini_navH + i) >= 0 && (col_ini_navH + i) < tamanhoTabuleiro){
                tabuleiro[lin_ini_navH][col_ini_navH + i] = 3;
            }
    }

    // Preenchendo o navio Vertical na matriz e testando limites do tabuleiro:
    for (int i = 0; i < tamanhoNavio; i++){
        if (lin_ini_navV >= 0 && lin_ini_navV < tamanhoTabuleiro &&
            (col_ini_navV + i) >= 0 && (col_ini_navV + i) < tamanhoTabuleiro){
                tabuleiro[lin_ini_navV + i][col_ini_navV] = 3;
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