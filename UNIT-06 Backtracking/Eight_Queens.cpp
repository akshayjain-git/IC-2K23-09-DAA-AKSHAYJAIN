#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int n = board.size();

    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solveQueens(vector<vector<int>>& board, int col) {
    int n = board.size();
    if (col >= n) return true;

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            if (solveQueens(board, col + 1)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    const int n = 8;
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveQueens(board, 0)) {
        cout << "No solution exists" << endl;
        return 0;
    }

    cout << "8-Queens solution:" << endl;
    for (auto row : board) {
        for (int cell : row) cout << cell << " ";
        cout << endl;
    }

    return 0;
}
