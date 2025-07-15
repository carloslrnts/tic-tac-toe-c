#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char board[3][3];

void resetBoard() {
    int i, j;
    char ch = '1';
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

void displayBoard() {
	system("cls");
    int i;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

void playGame() {
    int player = 1, choice, row, col, moves = 0;
    char mark;

    do {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter your choice (1-9): ", player);
        scanf("%d", &choice);

        choice--;

        row = choice / 3;
        col = choice % 3;

        if (choice >= 0 && choice < 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = mark;
            moves++;
        } else {
            printf("Invalid move! Try again.\n");
            player--;
        }

        if (checkWin()) {
            displayBoard();
            printf("==> Player %d wins!\n", player);
            return;
        }

        player++;
    } while (moves < 9);

    displayBoard();
    printf("==> It's a draw!\n");
}
