	4/23/2024:
	- Set up the project repository and basic file structure (main.cpp)
	- created initial versions of board.h and board.cpp to manage the game grid and handle basic operations like displaying the board and making moves

	4/24/2024:
	- implemented the game.h and game.cpp classes for the game logic
	- starting and ending the game
	- switching turns between players
	- Added win checking logic in the board classes for horizontal, verticla, and diagonal wins

	4/26/2024:
	- Integrated simple AI opponent logic using a placeholder strategy for testing game mechanics.
	- AI.h & AI.cpp
	- Added evaluation functions for the AI to assess the board state

	4/28/2024:
	- Made the AI opponent more logical by implementing a minimax algorithm to handle it's decision-making

	4/30/2024:
	- Improved the AI opponent with alpha-beta pruning to optimize the minimax search process
	- Implemented error handling to manage characters outside of 0-6, so that only valid column inputs are viable

	5/1/2024:
	- Added borders to the gird/board for better readability