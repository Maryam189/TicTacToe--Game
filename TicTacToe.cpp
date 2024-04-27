#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <windows.h> 

using namespace std;

// Function prototypes
void print_board(char arr[3][3]);
void clear(char arr[3][3]);
void input(int player, char arr[3][3]);
void get(char arr[3][3]);

// Functions for checking win conditions
bool diag_right(char ch, char arr[3][3]);
bool diag_left(char ch, char arr[3][3]);
bool row(int num, char ch, char arr[3][3]);
bool col(int num, char ch, char arr[3][3]);
bool full(char arr[3][3]);
bool end(char ch, char arr[3][3]);

// Function to set text color
void setConsoleColor(WORD color) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput, color);
}

int main() {
    srand(time(NULL));
    char board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };

    int choice=1;

    // Main game loop
    while(choice!=0) {
        clear(board);
        setConsoleColor(14); // Yellow color for game title
        cout << "    *** Tic Tac Toe Game ***\n\n";
        setConsoleColor(7); // Reset to default console color
        do {
            print_board(board);
            input(1, board);
            if(end('X', board) || end('O', board) || full(board))
                break;
            get(board);
        } while(!end('X', board) && !end('O', board) && !full(board));

        print_board(board);

        // Display game outcome
        if(end('X', board)) {
            setConsoleColor(10); // Green color for winning message
            cout << "\n\t  *** You WON ***\n";
        } else if(end('O', board)) {
            setConsoleColor(12); // Red color for losing message
            cout << "\n\t  *** Computer WON ***\n";
        } else {
            setConsoleColor(11); // Cyan color for draw message
            cout << "\n\t  *** MATCH DRAW ***\n";
        }
        setConsoleColor(7); // Reset to default console color
        cout << "\t  Press 0 to exit game\n";
        cin >> choice;
        if(choice == 0) {
            cout << "\n\t  GOODBYE!\n\n";
        }
    }
}

// Function to clear the board
void clear(char arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            arr[i][j] = ' ';
    }
}

// Function to print the game board
void print_board(char arr[3][3]) {
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << arr[2][0] << "  |  " << arr[2][1] << "  |  " << arr[2][2] << "  \n";
    cout << "\t\t     |     |     \n";
}

// Function for player input
void input(int player, char arr[3][3]) {
    int temp[2] = {-1};
    int box = 0;
    char turn;
    if(player == 1)
        turn = 'X';
    else 
        turn = 'O';

    bool check = false;
    do {
        cout << "\n\t  [" << turn << "] Player " << player << "(1-9): "; 
        cin >> box;
        if(box < 0 || box > 9) {
            cout << "Invalid location! Enter Again.\n";
            continue;
        }
        for(int i = 0, count = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                count++;
                if(box == count) {
                    temp[0] = i;
                    temp[1] = j;
                }
            }
        }
        if(arr[temp[0]][temp[1]] != ' ')
            cout << "Space Full! Enter Again.\n";
    } while(arr[temp[0]][temp[1]] != ' ');
    arr[temp[0]][temp[1]] = turn;
}

// Function for computer input
void get(char arr[3][3]) {
    int temp[2] = {-1};
    do {
        temp[0] = rand() % 3;
        temp[1] = rand() % 3;
    } while(arr[temp[0]][temp[1]] != ' ');
    arr[temp[0]][temp[1]] = 'O';
}

// Function to check diagonal win condition (right)
bool diag_right(char ch, char arr[3][3]) {
    char result;
    result = (ch == arr[0][2] && ch == arr[1][1] && ch == arr[2][0]);
    return result;
}

// Function to check diagonal win condition (left)
bool diag_left(char ch, char arr[3][3]) {
    char result;
    result = (ch == arr[0][0] && ch == arr[1][1] && ch == arr[2][2]);
    return result;
}

// Function to check row win condition
bool row(int num, char ch, char arr[3][3]) {
    char result;
    result = (ch == arr[num][0] && ch == arr[num][1] && ch == arr[num][2]);
    return result;
}

// Function to check column win condition
bool col(int num, char ch, char arr[3][3]) {
    char result;
    result = (ch == arr[0][num] && ch == arr[1][num] && ch == arr[2][num]);
    return result;   
}

// Function to check if the board is full
bool full(char arr[3][3]) {
    bool result = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(arr[i][j] == ' ')
                result = false;
        }
    }
    return result;
}

// Function to check if the game has ended
bool end(char ch, char arr[3][3]) {
    bool result = (diag_right((ch), arr) || diag_left((ch), arr) || row(0, ch, arr) || 
                   row(1, ch, arr) || row(2, ch, arr) || col(0, ch, arr) || 
                   col(1, ch, arr) || col(2, ch, arr));
    return result;
}
