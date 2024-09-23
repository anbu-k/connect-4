/*
 * Author: Anbu Krishnan
 * 
 * game.cpp manages the players' turns, the game state, and the interaction between the 
 * player and the opponent.
 */

#include "game.h"
#include <iostream>
#include <limits>

Game::Game() : board(), ai('O') {}  

void Game::resetBoard() {
    board = Board();
}

bool Game::playGame() {
    char choice;
    char currentPlayer = 'X';
    bool gameWon = false;

    resetBoard();

    while (!gameWon && !isBoardFull()) {
        board.printBoard();
        bool isComputer = (currentPlayer == 'O');
        playerTurn(currentPlayer, isComputer);
        gameWon = checkWin(currentPlayer);

        if (gameWon) {
            std::cout << (isComputer ? "" : "Player") << " " << currentPlayer << " wins!\n";
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (!gameWon) {
        std::cout << "The game is a draw!\n";
    }

    board.printBoard();

    std::cout << "Do you want to play again? (Y/N): ";
    std::cin >> choice;
    choice = toupper(choice);

    if (choice == 'Y') {
        resetBoard();
        return true;
    } else {
        std::cout << "Thanks for playing! Goodbye." << std::endl;
        return false;
    }
}

void Game::playerTurn(char playerSymbol, bool isComputer) {
    if (isComputer) {
        int column = ai.chooseColumn(board);
        board.makeMove(column, playerSymbol);
        std::cout << "Computer (Player " << playerSymbol << ") plays in column " << column << std::endl;
    } else {
        int column;
        std::cout << "Player " << playerSymbol << " (you), enter a column (0-6): ";
        while (!(std::cin >> column) || column < 0 || column >= 7 || !board.isValidMove(column)) {
            if (std::cin.fail()) { 
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a column number between 0 and 6: ";
            } else if (column < 0 || column >= 7) {
                std::cout << "Column out of bounds. Please enter a column number between 0 and 6: ";
            } else if (!board.isValidMove(column)) {
                std::cout << "Column " << column << " is full. Please choose another column: ";
            }
        }

        board.makeMove(column, playerSymbol);
    }
}


bool Game::checkWin(char playerSymbol) {
    return board.checkHorizontalWin(playerSymbol) || board.checkVerticalWin(playerSymbol) || board.checkDiagonalWin(playerSymbol);
}

bool Game::isBoardFull() {
    return board.isFull();
}
