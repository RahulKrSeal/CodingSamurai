//Task 2 :  TIC - TAC - TOE Game

#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;
char board[ROWS][COLS];
bool gameOver = false;

void initializeBoard() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout<<"\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout <<" "<<board[i][j];
            if (j < COLS - 1) cout <<" "<< '|';
        }
        cout << endl;
        if (i < ROWS - 1) {
            cout << "-----------" << endl;
        }
    }
}

bool checkWin(char mark) {
    for (int i = 0; i < ROWS; ++i) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
            return true;
    }

    for (int j = 0; j < COLS; ++j) {
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark)
            return true;
    }

    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void getPlayerMove(int currentPlayer) {
    int row, col;
    cout << "\nPlayer " << currentPlayer << " : Enter your move (row and column): ";
    cin >> row >> col;

    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
        cout << "\nInvalid move. Try again: ";
        cin >> row >> col;
    }

    if (currentPlayer == 1)
        board[row - 1][col - 1] = 'X';
    else
        board[row - 1][col - 1] = 'O';
}

void playGame() {
    int currentPlayer = 1;
    initializeBoard();

    while (!gameOver) {
        displayBoard();
        getPlayerMove(currentPlayer);

        if (checkWin('X')) {
            displayBoard();
            cout << "\nPlayer 1 wins!\n" << endl;
            gameOver = true;
        } else if (checkWin('O')) {
            displayBoard();
            cout << "\nPlayer 2 wins!\n" << endl;
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "\nIt's a draw!\n" << endl;
            gameOver = true;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

int main() {
    printf("\nTIC - TAC - TOE \n\n");
    playGame();
    return 0;
}
