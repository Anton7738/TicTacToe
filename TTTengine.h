#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <unistd.h>
#include "Board.h"

#ifndef TTTENGINE
#define TTTENGINE
    void playGame(char board[7][13]);

    bool checkWin(char board[7][13]);

    bool checkDraw(char board[7][13]);
#endif