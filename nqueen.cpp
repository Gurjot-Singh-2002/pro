#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int board[20];  // board[i] stores column position of queen in row i

bool isSafe(int row, int col, int n) {
    for (int i = 1; i < row; i++) {
        // Check same column or diagonal conflict
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void printBoard(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueen(int row, int n) {
    if (row > n) {
        printBoard(n);  // print solution when all queens are placed
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col, n)) {
            board[row] = col;
            solveNQueen(row + 1, n);  // place next queen
            // backtrack automatically after returning
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    solveNQueen(1, n);  // Start placing from row 1
    return 0;
}

