#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

void printBoard(const vector<int>& board, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
    cout << endl;
    usleep(500000); // Sleep for 0.5 seconds to visualize the steps
}

bool isSafe(const vector<int>& board, int row, int col, int N) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(vector<int>& board, int row, int N, vector<vector<int>>& solutions) {
    if (row == N) {
        solutions.push_back(board);
        printBoard(board, N); 
        cout << "Solution found!" << endl;
        usleep(500000); 
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row] = col;
            printBoard(board, N); 
            solveNQueensUtil(board, row + 1, N, solutions);
            board[row] = -1; 
            printBoard(board, N); 
        }
    }
}

void solveNQueens(int N) {
    vector<int> board(N, -1);
    vector<vector<int>> solutions;
    solveNQueensUtil(board, 0, N, solutions);

    if (solutions.empty()) {
        cout << "No solution exists for " << N << " queens." << endl;
    } else {
        cout << "Final Solutions:\n";
        for (const auto& sol : solutions) {
            printBoard(sol, N);
        }
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
