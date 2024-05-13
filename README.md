# Tic Tac Toe Game in C++
This Tic Tac Toe game is implemented in C++ and offers an interactive console-based experience where a player competes against a computer-controlled opponent. Utilizing basic concepts of arrays and functions, the game features dynamic input validation, color-coded console output for clarity, and automated checks for win conditions across rows, columns, and diagonals. Designed for simplicity and ease of use, this application demonstrates practical application of programming fundamentals in creating a fun and engaging game environment.

## Features

- **Two-Player Game**: Play against a computer AI that makes random moves.
- **Colorful Console Interface**: Utilizes console color attributes to enhance gameplay visibility and interaction.
- **Dynamic Input Validation**: Ensures all inputs are valid and handles incorrect or occupied spaces gracefully.
- **Win Condition Checks**: Includes comprehensive checks for win conditions including rows, columns, and diagonals.
- **Board Reset**: Automatically clears the board after a game round ends.

## Prerequisites

To run this game, you will need:
- A C++ compiler that supports C++11 (e.g., GCC, Clang, MSVC)
- Windows environment, as the application uses Windows-specific headers for setting console colors.

## Compilation and Execution

Compile the game using a C++ compiler that supports the Windows.h library. For example, if you are using GCC, you can compile the program with the following command:

```bash
g++ -o TicTacToe TicTacToe.cpp
```

To run the game, simply execute the compiled binary:

```bash
./TicTacToe
```

# Tic Tac Toe Game in C++

## Gameplay Instructions

- **Game Board**: The game board consists of a 3x3 grid. Each cell can be selected by entering a number from 1 to 9.
- **Players**: Player 1 is represented by 'X' and the computer is represented by 'O'.
- **Making a Move**: On your turn, enter a number to place your 'X' in the corresponding grid position.
- **Game Progress**: The game checks for a win or draw after each move.
- **Game End**: If a player wins, the game announces the winner and resets the board for another round. If it's a draw, the game will also reset.
- **Exiting the Game**: To exit the game, enter '0' when prompted after a game round.

## Functions

- **`print_board()`**: Displays the current state of the game board.
- **`clear()`**: Clears the game board for a new game.
- **`input()`**: Handles the player's input.
- **`get()`**: Generates the computer's move.
- **`diag_right()`, `diag_left()`, `row()`, `col()`**: These functions check for win conditions.
- **`full()`**: Checks if the board is fully occupied.
- **`end()`**: Determines if the game has ended.

## Contributing
**Contributions are Welcome!** Please send me a pull request or open an issue to discuss your ideas. If there's anything else you'd like to know about it, let me know. Feel free to reach me out at Maryamkhalid590@gmail.com


