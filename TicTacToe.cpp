#include <iostream>
using namespace std;

int main() {
    const int board = 3;
    char pattern[board][board] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    char symbol = 'X';
    int row, col;
    while (true) {
        for (int rows = 0; rows < board; rows++) {
            for (int columns = 0; columns < board; columns++) {
                cout << pattern[rows][columns];
                if (columns <= 1) {
                    cout << " | ";
                }
            }
            cout << endl;
            if (rows <= 1) {
                cout << "---------" << endl;
            }
        }

       
        cout << "Enter the value to enter (0, 1, or 2): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            if (pattern[row][col] == ' ') {

                pattern[row][col] = symbol;
            }
            else {
                cout << "There is already a symbol at this address. Enter any other coordinates: "<<endl;
                continue;
            }
        }
        else {
            cout << "Incorrect Entry" << endl;
            continue;
        }

      if   ((pattern[0][0] == symbol && pattern[0][1] == symbol && pattern[0][2] == symbol) ||
            (pattern[1][0] == symbol && pattern[1][1] == symbol && pattern[1][2] == symbol) ||
            (pattern[2][0] == symbol && pattern[2][1] == symbol && pattern[2][2] == symbol) ||
            (pattern[0][0] == symbol && pattern[1][1] == symbol && pattern[2][2] == symbol) ||
            (pattern[0][0] == symbol && pattern[1][0] == symbol && pattern[2][0] == symbol) ||
            (pattern[0][1] == symbol && pattern[1][1] == symbol && pattern[2][1] == symbol) ||
            (pattern[0][2] == symbol && pattern[1][2] == symbol && pattern[2][2] == symbol) ||
            (pattern[0][2] == symbol && pattern[1][1] == symbol && pattern[2][0] == symbol)) {
            for (int rows = 0; rows < 3; rows++) {
                for (int coloumns = 0; coloumns < 3; coloumns++) {
                    cout << pattern[rows][coloumns];
                    if (coloumns< 2) {
                        cout << " | ";
                    }
                }
                cout << endl;
                if (rows < 2) {
                    cout << "---------" << endl;
                }
            }
            cout << "Player " << symbol << " wins!" << endl;
            break;
        } 

        bool tie = true;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (pattern[row][col] == ' ') {
                    tie = false;
                    break;
                }
            }
            if (!tie) {
                break;
            }
        }

        if (tie) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    cout << pattern[row][col];
                    if (col < 2) {
                        cout << " | ";
                    }
                }
                cout << endl;
                if (row < 2) {
                    cout << "---------" << endl;
                }
            }
            cout << "It's a draw!" << endl;
            break;
        }

        if (symbol == 'X') {
            symbol = 'O';
        }
        else {
            symbol = 'X';
        }
    }

    return 0;
}
