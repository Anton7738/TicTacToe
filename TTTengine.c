#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <unistd.h>
#include "Board.h"
#include "TTTengine.h"
#include "Bot.h"

int gameMode;

int playerScore = 0;
int computerScore = 0;

int playerOneScore = 0;
int playerTwoScore = 0;

void playGame(char board[7][13]) {

    bool repTurn = true;
    bool repGame = true;

    printf("\nSelect game mode:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs Computer\n");
    printf("Select mode>> ");
    scanf("%d", &gameMode);
    
    while (!(gameMode == 1 || gameMode == 2)) {
        printf("Error:: Usage: Invalid Option Selected\n");
        printf("Select >> ");
        scanf("%d", &gameMode);
    }

    while (repGame) {

        printf("\n======== NEW GAME ========\n\n");
        printf("Scores:\n");

        if (gameMode == 1) {
            printf("\n\tPlayer 1: %d\n", playerOneScore);
            printf("\tPlayer 2: %d\n\n", playerTwoScore);
        }

        else if (gameMode == 2) {
            printf("\n\tPlayer: %d\n", playerScore);
            printf("\tComputer: %d\n\n", computerScore);
        }
        
        /* TURNSIDE variabe (state machine)

        For player vs player:
            0: player 1
            1: player 2
        
        For player vs computer:
            0: player
            1: computer
        */
        int turnSide = 0;
        int selectedTile;

        while (repTurn) {

            // Player vs Player Logic
            if (gameMode == 1) {

                printBoard(board);
                
                if (turnSide == 0) {
                    printf("\nPlayer 1's Turn!\n");
                    printf("Select tile >> ");
                    scanf("%d", &selectedTile);
                    printf("\n");

                    abstPutPiece(board, 'X', selectedTile);

                    turnSide = 1;
                }

                else if (turnSide == 1) {
                    printf("\nPlayer 2's Turn!\n");
                    printf("Select tile >> ");
                    scanf("%d", &selectedTile);
                    printf("\n");

                    abstPutPiece(board, 'O', selectedTile);

                    turnSide = 0;
                }
            }

            // Player vs Computer Logic
            else if (gameMode == 2) {

                printf("This thing doesn't fucking work\n\n");

                printBoard(board);
                
                if (turnSide == 0) {
                    printf("\nPlayer's Turn!\n");
                    printf("Select tile >> ");
                    scanf("%d", &selectedTile);
                    printf("\n");

                    abstPutPiece(board, 'X', selectedTile);

                    turnSide = 1;
                }

                else if (turnSide == 1) {

                    sleep(0.5);
                    printf("\nComputer's Turn!\n\n");
                    sleep(1.5);

                    machDecision(board, 'O');

                    turnSide = 0;
                }
            }

            if (checkWin(board) || checkDraw(board)) {
                    break;
            }
            
        }

        int playAgain;

        printf("\nPlay again?\n");
        printf("1: Continue\n");
        printf("2: Quit\n");

        printf("Select option >> ");
        scanf("%d", &playAgain);

        while (!(playAgain == 1 || playAgain == 2)) {
            printf("Error:: Usage: Invalid Option Selected\n");
            printf("Select option >> ");
            scanf("%d", &gameMode);
        }

        if (playAgain == 1) {
            repGame = true;
            resetBoard(board);
        }

        else if (playAgain == 2) {
            playAgain = false;
            exit(0);
        }
    }   
}

bool checkWin(char board[7][13]) {

    /* 
    To make checkWin more efficient, could separate function into
    checkWinX and checkWinO so that not as many conditionals need
    to be checked.
    */

    bool gameWon = false;
 
    // First Row Win
    if (board[1][2] == 'X' && board[1][6] == 'X' && board[1][10] == 'X') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 1 Wins!\n");
            playerOneScore++;
        }
        else if (gameMode == 2) {
            printf("\nPlayer Wins!\n");
            playerScore++;
        }
    }
    if (board[1][2] == 'O' && board[1][6] == 'O' && board[1][10] == 'O') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 2 Wins!\n");
            playerTwoScore++;
        }
        else if (gameMode == 2) {
            printf("\nComputer Wins!\n");
            computerScore++;
        }
    }
    // Second Row Win
    if (board[3][2] == 'X' && board[3][6] == 'X' && board[3][10] == 'X') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 1 Wins!\n");
            playerOneScore++;
        }
        else if (gameMode == 2) {
            printf("\nPlayer Wins!\n");
            playerScore++;
        }
    }
    if (board[3][2] == 'O' && board[3][6] == 'O' && board[3][10] == 'O') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 2 Wins!\n");
            playerTwoScore++;
        }
        else if (gameMode == 2) {
            printf("\nComputer Wins!\n");
            computerScore++;
        }
    }
    // Third Row Win
    if (board[5][2] == 'X' && board[5][6] == 'X' && board[5][10] == 'X') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 1 Wins!\n");
            playerOneScore++;
        }
        else if (gameMode == 2) {
            printf("\nPlayer Wins!\n");
            playerScore++;
        }
    }
    if (board[5][2] == 'O' && board[5][6] == 'O' && board[5][10] == 'O') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 2 Wins!\n");
            playerTwoScore++;
        }
        else if (gameMode == 2) {
            printf("\nComputer Wins!\n");
            computerScore++;
        }
    }
    // First Column Win
    if (board[1][2] == 'X' && board[3][2] == 'X' && board[5][2] == 'X') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 1 Wins!\n");
            playerOneScore++;
        }
        else if (gameMode == 2) {
            printf("\nPlayer Wins!\n");
            playerScore++;
        }
    }
    if (board[1][2] == 'O' && board[3][2] == 'O' && board[5][2] == 'O') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 2 Wins!\n");
            playerTwoScore++;
        }
        else if (gameMode == 2) {
            printf("\nComputer Wins!\n");
            computerScore++;
        }
    }
    // Second Column Win
    if (board[1][6] == 'X' && board[3][6] == 'X' && board[5][6] == 'X') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 1 Wins!\n");
            playerOneScore++;
        }
        else if (gameMode == 2) {
            printf("\nPlayer Wins!\n");
            playerScore++;
        }
    }
    if (board[1][6] == 'O' && board[3][6] == 'O' && board[5][6] == 'O') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 2 Wins!\n");
            playerTwoScore++;
        }
        else if (gameMode == 2) {
            printf("\nComputer Wins!\n");
            computerScore++;
        }
    }
    // Third Column Win
    if (board[1][10] == 'X' && board[3][10] == 'X' && board[5][10] == 'X') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 1 Wins!\n");
            playerOneScore++;
        }
        else if (gameMode == 2) {
            printf("\nPlayer Wins!\n");
            playerScore++;
        }
    }
    if (board[1][10] == 'O' && board[3][10] == 'O' && board[5][10] == 'O') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 2 Wins!\n");
            playerTwoScore++;
        }
        else if (gameMode == 2) {
            printf("\nComputer Wins!\n");
            computerScore++;
        }
    }
    // Diagonal / Win
    if (board[5][2] == 'X' && board[3][6] == 'X' && board[1][10] == 'X') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 1 Wins!\n");
            playerOneScore++;
        }
        else if (gameMode == 2) {
            printf("\nPlayer Wins!\n");
            playerScore++;
        }
    }
    if (board[5][2] == 'O' && board[3][6] == 'O' && board[1][10] == 'O') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 2 Wins!\n");
            playerTwoScore++;
        }
        else if (gameMode == 2) {
            printf("\nComputer Wins!\n");
            computerScore++;
        }
    }
    // Diagonal \ Win
    if (board[1][2] == 'X' && board[3][6] == 'X' && board[5][10] == 'X') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 1 Wins!\n");
            playerOneScore++;
        }
        else if (gameMode == 2) {
            printf("\nPlayer Wins!\n");
            playerScore++;
        }
    }
    if (board[1][2] == 'O' && board[3][6] == 'O' && board[5][10] == 'O') {
        printf("\n");
        printBoard(board);
        gameWon = true;
        if (gameMode == 1) {
            printf("\nPlayer 2 Wins!\n");
            playerTwoScore++;
        }
        else if (gameMode == 2) {
            printf("\nComputer Wins!\n");
            computerScore++;
        }
    }

    return gameWon;
}

bool checkDraw(char board[7][13]) {
    
    bool gameDraw = false;

    if ((board[1][2] == 'X' || board[1][2] == 'O') &&
        (board[1][6] == 'X' || board[1][6] == 'O') &&
        (board[1][10] == 'X' || board[1][10] == 'O') &&
        (board[3][2] == 'X' || board[3][2] == 'O') &&
        (board[3][6] == 'X' || board[3][6] == 'O') &&
        (board[3][10] == 'X' || board[3][10] == 'O') &&
        (board[5][2] == 'X' || board[5][2] == 'O') &&
        (board[5][6] == 'X' || board[5][6] == 'O') &&
        (board[5][10] == 'X' || board[5][10] == 'O')) {
            gameDraw = true;
            printf("\n");
            printBoard(board);
            printf("\nDraw\n");
        }

    return gameDraw;
}