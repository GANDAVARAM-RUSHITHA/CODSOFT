//TIC-TAC-TOE GAME 
#include <iostream>
using namespace std;

// Function prototypes
void displayBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
void switchPlayer(char &player);

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    char player = 'X';
    int choice;
    bool gameWon = false;
    bool draw = false;

    while (!gameWon && !draw) {
        displayBoard(board);
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> choice;

        // Update the board
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
        board[row][col] = player;

        // Check for win
        gameWon = checkWin(board, player);
        if (!gameWon) {
            draw = checkDraw(board);
            if (!draw) {
                switchPlayer(player);
            }
        }
    }

    displayBoard(board);
    if (gameWon) {
        cout << "Player " << player << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

// Function to display the game board
void displayBoard(char board[3][3]) {
    system("clear"); // Use "cls" for Windows
    cout << "Tic-Tac-Toe Game" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
void switchPlayer(char &player) {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}
