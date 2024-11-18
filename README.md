C++ Connect-4 Engine

This is a text-based Connect Four game implemented in C++ where you play versus the computer

Structure: 

main.cpp: The main entry point for the game 

game.h/game.cpp: Implements the game logic 

board.h/board.cpp: Manages the game board and checks for win conditions 

AI.h/AI.cpp: Implements the opponent logic using minimax and alpha-beta pruning

Requirements:

C++ Compiler supporting C++11 Make

Compile with:

$ make

Execute with:

$ ./connect4

Clean with:

$ make clean

Rules: 

1. Choose a column to drop your disc 

2. The game alternates between you and the computer 

3. The first player to get 4 in a row vertically, horizontally, or diagonally wins 

4. If the board fills up and nobody wins the game ends in a draw

(Opponent difficulty is medium/hard)

Tips:

Control the Center,
Force defensive moves,
Try to create double-ended threats
