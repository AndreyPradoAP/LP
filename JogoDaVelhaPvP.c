#include <stdio.h>
#include <windows.h>
#include <conio.h>

void printarTabuleiro(char tabuleiro[3][3]){
    system("cls");
    printf("-----TABULEIRO-----\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c ", tabuleiro[i][j]);
        }
        
        printf("\n");
    }
    printf("\n");
}

int jogadaInvalida(int jogador, int movimento){
    printf("\n\tJogada inválida!\n");
    printf("\tJogador %d: Digite novamente o local do tabuleiro\n\t", jogador);
    scanf("%d", &movimento);

    return movimento;
}


int main() {
    int movimento, linha, coluna, vitoriaColuna, vitoriaLinha, vitoriaDiagonal, jogador = 1;
    char tabuleiro[3][3] = {{'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'}};

    for(int c = 0; c < 9; c++){
        printarTabuleiro(tabuleiro);
        
        printf("Jogador %d:\n", jogador);
        printf("Digite o local do tabuleiro para realizar a jogada\n");
        scanf("%d", &movimento);

        // Verifica se o que foi digitado é valido
        while (0 > movimento || movimento > 9){
            movimento = jogadaInvalida(jogador, movimento);
        }    
        
        // Contas para determinar ponto do tabuleiro
        linha = (int) movimento / 3;
        coluna = (int) movimento % 3;

        while(tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O'){
            movimento = jogadaInvalida(jogador, movimento);

            linha = (int) movimento / 3;
            coluna = (int) movimento % 3;
        }
        
        if(jogador == 1){
            tabuleiro[linha][coluna] = 'X';
        }
        else{
            tabuleiro[linha][coluna] = 'O';
        }

        // Verifica se foi vitória
        for(int i = 0; i < 3; i++){
            if(tabuleiro[linha][coluna] == tabuleiro[linha][i]){
                vitoriaLinha++;
            }

            if(tabuleiro[linha][coluna] == tabuleiro[i][coluna]){
                vitoriaColuna++;
            }

            if (movimento % 2 == 0){
                if (movimento % 4 == 0){
                    if(tabuleiro[linha][coluna] == tabuleiro[i][i]){
                        vitoriaDiagonal++;
                    }
                }
            }
            
        }

        // Verifica se foi vitória (Diafonal secundária)
        if(movimento % 2 == 0){
            if(tabuleiro[linha][coluna] == tabuleiro[0][2] && tabuleiro[linha][coluna] == tabuleiro[1][1] && tabuleiro[linha][coluna] == tabuleiro[2][0]){
                vitoriaDiagonal = 3;
            }
        }
         
        if(vitoriaColuna == 3 || vitoriaLinha == 3 || vitoriaDiagonal == 3){
            printarTabuleiro(tabuleiro);
            printf("O Jogador%d é o vencedor!\n", jogador);
            return 0;
        }
        
        vitoriaLinha = 0;
        vitoriaColuna = 0;
        vitoriaDiagonal = 0;
        
        // Troca o jogador
        if(jogador == 1){
            jogador = 2;
        }
        else{
            jogador = 1;
        }
    }

    printarTabuleiro(tabuleiro);
    printf("Deu velha!");
}
