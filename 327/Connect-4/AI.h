/*
 * Author: Anbu Krishnan
 * 
 * Header file for AI opponent logic 
 */

#ifndef AI_H
#define AI_H

#include "board.h"

class AI {
public:
    AI(char playerSymbol);
    int chooseColumn(const Board& board); 
    int minimax(Board board, int depth, bool maximizingPlayer, int alpha, int beta);
    int evaluateBoard(const Board& board);
    int evaluateLine(const Board& board, char symbol, int length);

private:
    char playerSymbol; 
};

#endif 