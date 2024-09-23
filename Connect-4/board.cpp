/*
 * Author: Anbu Krishnan
 * 
 * board.cpp manages the game grid.
 * It handles operations such as initializing the grid, making moves,
 * checking for wins, and determining if the board is full. 
 */

#include "board.h"
#include <iostream>

Board::Board() : grid(ROWS, std::vector<char>(COLUMNS, '.')) {}

void Board::printBoard() const {
    std::cout << "+";
    for (int j = 0; j < COLUMNS; j++) {
        std::cout << "---+";
    }
    std::cout << "\n";

    for (int i = 0; i < ROWS; i++) {
        std::cout << "|";  
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << " " << grid[i][j] << " |";  
        }
        std::cout << "\n";

        // row borders
        std::cout << "+";
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << "---+";
        }
        std::cout << "\n";
    }

    
    std::cout << "  ";
    for (int j = 0; j < COLUMNS; j++) {
        std::cout << " " << j << "  ";
    }
    std::cout << "\n";
}

bool Board::isValidMove(int column) const {
    return grid[0][column] == '.';
}

void Board::makeMove(int column, char playerSymbol) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (grid[i][column] == '.') {
            grid[i][column] = playerSymbol;
            break;
        }
    }
}

bool Board::checkHorizontalWin(char playerSymbol) const {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col <= COLUMNS - 4; ++col) {
            if (grid[row][col] == playerSymbol &&
                grid[row][col + 1] == playerSymbol &&
                grid[row][col + 2] == playerSymbol &&
                grid[row][col + 3] == playerSymbol) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkVerticalWin(char playerSymbol) const {
    for (int col = 0; col < COLUMNS; ++col) {
        for (int row = 0; row <= ROWS - 4; ++row) {
            if (grid[row][col] == playerSymbol &&
                grid[row + 1][col] == playerSymbol &&
                grid[row + 2][col] == playerSymbol &&
                grid[row + 3][col] == playerSymbol) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkDiagonalWin(char playerSymbol) const {
    for (int row = 0; row <= ROWS - 4; ++row) {
        for (int col = 0; col <= COLUMNS - 4; ++col) {
            if (grid[row][col] == playerSymbol &&
                grid[row + 1][col + 1] == playerSymbol &&
                grid[row + 2][col + 2] == playerSymbol &&
                grid[row + 3][col + 3] == playerSymbol) {
                return true;
            }
        }
    }

    // descending diagonals
    for (int row = 0; row <= ROWS - 4; ++row) {
        for (int col = 3; col < COLUMNS; ++col) {
            if (grid[row][col] == playerSymbol &&
                grid[row + 1][col - 1] == playerSymbol &&
                grid[row + 2][col - 2] == playerSymbol &&
                grid[row + 3][col - 3] == playerSymbol) {
                return true;
            }
        }
    }

    return false;
}

bool Board::isFull() const {
    for (int i = 0; i < COLUMNS; i++) {
        if (grid[0][i] == '.') {
            return false;
        }
    }
    return true;
}
