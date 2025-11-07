#include<iostream>
using namespace std;
// Place N queens on an NxN chessboard so that no two queens attack each other.

int n_queens_util(int board[][10], int n, int row) {
    if (row == n) {
        // Print the board configuration
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; col++) {
        // Check if placing a queen at (row, col) is safe
        bool safe = true;
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1) {
                safe = false;
                break;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                safe = false;
                break;
            }
        }
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 1) {
                safe = false;
                break;
            }
        }

        if (safe) {
            board[row][col] = 1; // Place queen
            count += n_queens_util(board, n, row + 1);
            board[row][col] = 0; // Backtrack
        }
    }
    return count;
}

int main(){
    int n;
    cout << "Enter the value of N for N-Queens: ";
    cin >> n;
    int board[10][10] = {0};
    cout << "All possible configurations of " << n << "-Queens are:" << endl;
    int total_solutions = n_queens_util(board, n, 0);
    cout << "Total solutions: " << total_solutions << endl;
    return 0;
}