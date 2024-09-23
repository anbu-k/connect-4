/*
 * Author: Anbu Krishnan
 * 
 * Header file for game logic
 */

#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "AI.h" 

class Game {
public:
    Game();
    bool playGame();
    void resetBoard();
    void playerTurn(char playerSymbol, bool isComputer);  

private:
    Board board;
    AI ai;  
    bool checkWin(char playerSymbol);
    bool isBoardFull();
};

#endif 