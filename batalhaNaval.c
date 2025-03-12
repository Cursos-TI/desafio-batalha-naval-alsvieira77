#include <stdio.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Funções para construir as matrizes de habilidade
void construirHabilidadeCone(int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 0 && j == 2) || (i == 1 && j >= 1 && j <= 3) || (i == 2)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void construirHabilidadeCruz(int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void construirHabilidadeOctaedro(int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i == 0 && j == 2) || (i == 1 && j >= 1 && j <= 3) || (i == 2 && j == 2)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int origemLinha, int origemColuna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaTabuleiro = origemLinha + i - 2;
            int colunaTabuleiro = origemColuna + j - 2;
            if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 && colunaTabuleiro >= 0 && colunaTabuleiro < 10) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com o valor 0 para todas as posições

    // Coordenadas iniciais do navio
    int navioHorizontal[3] = {3, 3, 3}; // Posicionamento horizontal com tamanho 3
    int navioVertical[3] = {3, 3, 3}; // Posicionamento vertical

    // Posicionamento do navio horizontal na linha 2, começando na coluna 1
    int linhaHorizontal = 2;
    int colunaHorizontal = 1;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // Posiciona o navio vertical na coluna 4, começando na linha 5
    int linhaVertical = 5;
    int colunaVertical = 4;
    for (int i = 0; i < 3; i++){
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};
    
    // Posiciona o primeiro navio diagonal (da esquerda para a direita)
    int linhaDiagonal1 = 7;
    int colunaDiagonal1 = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = navioDiagonal1[i];
    }

    // Posiciona o segundo navio diagonal (da direita para a esquerda)
    int linhaDiagonal2 = 0;
    int colunaDiagonal2 = 9;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = navioDiagonal2[i];
    }

    // Construir e aplicar habilidades
    int habilidadeCone[5][5];
    int habilidadeCruz[5][5];
    int habilidadeOctaedro[5][5];

    construirHabilidadeCone(habilidadeCone);
    construirHabilidadeCruz(habilidadeCruz);
    construirHabilidadeOctaedro(habilidadeOctaedro);

    aplicarHabilidade(tabuleiro, habilidadeCone, 2, 2); // Exemplo de ponto de origem (2, 2)
    aplicarHabilidade(tabuleiro, habilidadeCruz, 5, 5); // Exemplo de ponto de origem (5, 5)
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 7, 7); // Exemplo de ponto de origem (7, 7)

    // Exibe o tabuleiro no console
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
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
