#include <iostream>
#include <cmath>
using namespace std;

int N;
int board[20]; // Adjustable size for larger boards

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int row) {
    if (row == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (solveNQueens(row + 1)) return true;
        }
    }
    return false;
}

int main() {
    cout << "Enter the size of the board (N): ";
    cin >> N;
    if (!solveNQueens(0)) {
        cout << "No solution exists for " << N << " queens." << endl;
    }
    return 0;
}
