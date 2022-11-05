#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include "TTTengine.h"

void main() {

    printf("\nTic-Tac-Toe!\n");

    // Initialization
    char tttBoard[7][13];
    //printf("%c\n", tttBoard[5][7]);

    resetBoard(tttBoard);
    //printf("%c\n", tttBoard[5][7]);

    printBoard(tttBoard);

    //printf("%c\n", tttBoard[5][2]);
    //printf("%c\n", tttBoard[5][7]);

    playGame(tttBoard);
}
