#include <stdio.h>
#include "game.h"

int main() {
    char playAgain;

    do {
        resetBoard();
        playGame();

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
