#include <stdio.h>
#include <stdlib.h>

#ifndef BOARD
#define BOARD
    void printBoard(char board[7][13]);

    void putPiece(char board[7][13], char XorO, int xPos, int yPos);

    void abstPutPiece(char board[7][13], char XorO, int tile);

    void resetBoard(char board[7][13]);

    char tileStatus(char board[7][13], int tile);
    
#endif