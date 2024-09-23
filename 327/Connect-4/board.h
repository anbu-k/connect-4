/*
 * Author: Anbu Krishnan
 * 
 * Header file for board logic 
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();
    void printBoard() const;
    bool isValidMove(int column) const;
    void makeMove(int column, char playerSymbol);
    bool checkHorizontalWin(char playerSymbol) const;
    bool checkVerticalWin(char playerSymbol) const;
    bool checkDiagonalWin(char playerSymbol) const;
    bool isFull() const;
  
    int getWidth() const { return COLUMNS; }
    int getRows() const {return ROWS; }
    char getCell(int row, int col) const { return grid[row][col]; }

private:
    static const int COLUMNS = 7;
    static const int ROWS = 6;
    std::vector<std::vector<char>> grid;
};

#endif 