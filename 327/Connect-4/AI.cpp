/*
 * Author: Anbu Krishnan
 * 
 * AI.h uses the minimax algorithm with alpha-beta pruning to determine the opponents optimal 
 * moves based on the current state of the game board. 
 */

#include "AI.h"
#include "board.h"
#include <limits>

AI::AI(char playerSymbol) : playerSymbol(playerSymbol) {}

int AI::chooseColumn(const Board& board) {
    int bestScore = std::numeric_limits<int>::min();
    int bestMove = 0;
    for (int col = 0; col < board.getWidth(); col++) {
        if (board.isValidMove(col)) {
            Board newBoard = board; 
            newBoard.makeMove(col, playerSymbol); 
            int score = minimax(newBoard, 5, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
            if (score > bestScore) {
                bestScore = score;
                bestMove = col;
            }
        }
    }
    return bestMove;
}

int AI::minimax(Board board, int depth, bool maximizingPlayer, int alpha, int beta) {
    if (depth == 0 || board.isFull()) {
        return evaluateBoard(board);
    }
    if (maximizingPlayer) {
        int maxEval = std::numeric_limits<int>::min();
	
        for (int col = 0; col < board.getWidth(); col++) {
            if (board.isValidMove(col)) {
                Board newBoard = board;
                newBoard.makeMove(col, playerSymbol);
                int eval = minimax(newBoard, depth - 1, false, alpha, beta);
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if (beta <= alpha) {
                    break; 
                }
            }
        }
	
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        for (int col = 0; col < board.getWidth(); col++) {
            if (board.isValidMove(col)) {
                Board newBoard = board;
                char opponentSymbol = (playerSymbol == 'X' ? 'O' : 'X');
                newBoard.makeMove(col, opponentSymbol);
                int eval = minimax(newBoard, depth - 1, true, alpha, beta);
                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);
                if (beta <= alpha) {
                    break; 
                }
            }
        }
        return minEval;
    }
}

int AI::evaluateBoard(const Board& board) {
    int score = 0;
    int centerIndex = board.getWidth() / 2;

    // Center column preference
    for (int row = 0; row < board.getRows(); row++) {
      if (board.getCell(row, centerIndex) == playerSymbol) {
            score += 3;  
        }
    }

    score += evaluateLine(board, playerSymbol, 4) * 100;  // potential wins
    score -= evaluateLine(board, playerSymbol == 'X' ? 'O' : 'X', 4) * 100;  // opponent potential wins

    return score;
}

int AI::evaluateLine(const Board& board, char symbol, int length) {
    int count = 0;

    // Horizontal checks
    for (int row = 0; row < board.getRows(); row++) {
        for (int col = 0; col <= board.getWidth() - length; col++) {
            bool allMatch = true;
            for (int i = 0; i < length; i++) {
                if (board.getCell(row, col + i) != symbol) {
                    allMatch = false;
                    break;
                }
            }
            if (allMatch) {
                count++;
            }
        }
    }

    // Vertical checks
    for (int col = 0; col < board.getWidth(); col++) {
        for (int row = 0; row <= board.getRows() - length; row++) {
            bool allMatch = true;
            for (int i = 0; i < length; i++) {
                if (board.getCell(row + i, col) != symbol) {
                    allMatch = false;
                    break;
                }
            }
            if (allMatch) {
                count++;
            }
        }
    }

    // Diagonal checks
    for (int row = 0; row <= board.getRows() - length; row++) {
        for (int col = 0; col <= board.getWidth() - length; col++) {
            bool allMatchAsc = true;
            bool allMatchDesc = true;
            for (int i = 0; i < length; i++) {
                if (board.getCell(row + i, col + i) != symbol) {
                    allMatchAsc = false;
                }
                if (board.getCell(row + i, col + length - i - 1) != symbol) {
                    allMatchDesc = false;
                }
            }
            if (allMatchAsc || allMatchDesc) {
                count++;
            }
        }
    }

    return count;
}

