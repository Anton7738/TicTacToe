#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

// Toggle to debug printBoard() function
//#define DEBUG_MODE

int strVertLen = 7;
int strHorizLen = 13;

char empty = ' ';
char vertical_line = '|';
char horiz_line = '-';
char placeholder = 'H';
char plus_line = '+';

// This is a message for future Anton

void printBoard(char board[7][13]) {

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 13; j++) {

            if (!(board[i][j] == 'X' || board[i][j] == 'O'
            || board[i][j] == '1' || board[i][j] == '2'
            || board[i][j] == '3' || board[i][j] == '4'
            || board[i][j] == '5' || board[i][j] == '6'
            || board[i][j] == '7' || board[i][j] == '8'
            || board[i][j] == '9')) {

                board[i][j] = empty;
                
                if (j % 4 == 0 && !(i == 0 || i == 6)) {
                    board[i][j] = vertical_line;
                    #ifdef DEBUG_MODE
                        printf("Vert");
                    #endif
                }
                if (j % 4 == 0 && (i == 0 || i == 6) ||
                ((i == 2 || i == 4)  && (j == 4 || j == 8))) {
                    board[i][j] = plus_line;
                    #ifdef DEBUG_MODE
                        printf("Plus");
                    #endif
                }
                if (j % 4 != 0 && i % 2 == 0) {
                    board[i][j] = horiz_line;
                    #ifdef DEBUG_MODE
                        printf("Hor");
                    #endif
                }
                if (j % 4 == 2 && i % 2 == 1) {
                    board[i][j] = empty;
                    #ifdef DEBUG_MODE
                        printf("Plac");
                    #endif
                }
            }
  

            #ifdef DEBUG_MODE
                printf(" ");
            #endif
        }
        #ifdef DEBUG_MODE
            printf("\n");
        #endif
    }

    #ifdef DEBUG_MODE
        printf("\n");
    #endif

    for (int n = 0; n < 7; n++) {
        for (int m = 0; m < 13; m++) {
            printf("%c", board[n][m]);
        }
        // When all columns of a row have printed, 
        // move to next row
        printf("\n");
    }
}

void putPiece(char board[7][13], char XorO, int xPos, int yPos) {
    board[xPos - 1][yPos - 1] = XorO;
}

void abstPutPiece(char board[7][13], char XorO, int tile) {
    switch (tile) {
        case 1:
            if (!(board[1][2] == 'X' || board[1][2] == 'O')) {
                putPiece(board, XorO, 2, 3);
            }
            else {
                printf("\nError:: Usage: Tile already chosen\n");
                printf("Turn passes to next player...\n\n");
            }
            break;
        case 2: 
            if (!(board[1][6] == 'X' || board[1][6] == 'O')) {
                putPiece(board, XorO, 2, 7);
            }
            else {
                printf("\nError:: Usage: Tile already chosen\n");
                printf("Turn passes to next player...\n\n");
            }
            break;
        case 3: 
            if (!(board[1][10] == 'X' || board[1][10] == 'O')) {
                putPiece(board, XorO, 2, 11);
            }
            else {
                printf("\nError:: Usage: Tile already chosen\n");
                printf("Turn passes to next player...\n\n");
            }
            break;
        case 4: 
            if (!(board[3][2] == 'X' || board[3][2] == 'O')) {
                putPiece(board, XorO, 4, 3);
            }
            else {
                printf("\nError:: Usage: Tile already chosen\n");
                printf("Turn passes to next player...\n\n");
            }
            break;
        case 5: 
            if (!(board[3][6] == 'X' || board[3][6] == 'O')) {
                putPiece(board, XorO, 4, 7);
            }
            else {
                printf("\nError:: Usage: Tile already chosen\n");
                printf("Turn passes to next player...\n\n");
            }
            break;
        case 6:
            if (!(board[3][10] == 'X' || board[3][10] == 'O')) {
                putPiece(board, XorO, 4, 11);
            }
            else {
                printf("\nError:: Usage: Tile already chosen\n");
                printf("Turn passes to next player...\n\n");
            } 
            break;
        case 7: 
            if (!(board[5][2] == 'X' || board[5][2] == 'O')) {
                putPiece(board, XorO, 6, 3);
            }
            else {
                printf("\nError:: Usage: Tile already chosen\n");
                printf("Turn passes to next player...\n\n");
            }
            break;
        case 8: 
            if (!(board[5][6] == 'X' || board[5][6] == 'O')) {
                putPiece(board, XorO, 6, 7);
            }
            else {
                printf("\nError:: Usage: Tile already chosen\n");
                printf("Turn passes to next player...\n\n");
            }
            break;
        case 9: 
            if (!(board[5][10] == 'X' || board[5][10] == 'O')) {
                putPiece(board, XorO, 6, 11);
            }
            else {
                printf("\nError:: Usage: Tile already chosen\n");
                printf("Turn passes to next player...\n\n");
            }
            break;
        default:
            printf("\nError:: Usage: Invalid tile selection\n");
            printf("Turn passes to next player...\n\n");
            break;
    }
}

void resetBoard(char board[7][13]) {
    putPiece(board,'1', 2, 3);
    putPiece(board,'2', 2, 7);
    putPiece(board,'3', 2, 11);
    putPiece(board,'4', 4, 3);
    putPiece(board,'5', 4, 7);
    putPiece(board,'6', 4, 11);
    putPiece(board,'7', 6, 3);
    putPiece(board,'8', 6, 7);
    putPiece(board,'9', 6, 11);
}

char tileStatus(char board[7][13], int tile) {

    char status;

    switch (tile) {
        case 1: 
            status = board[1][2];
            break;
        case 2: 
            status = board[1][6];
            break;
        case 3: 
            status = board[1][10];
            break;
        case 4: 
            status = board[3][2];
            break;
        case 5: 
            status = board[3][6];
            break;
        case 6: 
            status = board[3][10];
            break;
        case 7: 
            status = board[5][2];
            break;
        case 8: 
            status = board[5][6];
            break;
        case 9: 
            status = board[5][10];
            break;
        default: 
            printf("Error: Invalid Mapping or Retrieval\n");
    }

    // int intStatus = (int)status;

    // printf("intStatus: %d\n", intStatus);

    // if (intStatus >= 1 && intStatus <= 9) {
    //     printf("success!\n");
    // }

    return status;
}
