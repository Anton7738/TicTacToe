#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Board.h"
#include "TTTengine.h"
#include "Bot.h"

int turnCount = 0;

/* 
takes in XorO so that this can 
be changed in future if desired
*/
void machDecision(char board[7][13], char XorO) {

    turnCount++;

    tileStatus(board,7);

    //printf("%c\n\n", tileStatus(board, 7));
    
    // if (turnCount == 1) {
    //     srand(time(0));
    //     int lower = 1;
    //     int upper = 9;
    //     int num = (rand() % (upper - lower + 1)) + lower;
    //     while (tileStatus(board, num) != 1) {
    //         int num = (rand() % (upper - lower + 1)) + lower;
    //     }

        
        
    // }
    
}
