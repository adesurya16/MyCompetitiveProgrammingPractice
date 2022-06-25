#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &board, int n, int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 0;
}

bool solveKnightTour(vector<vector<int>> &board, int x, int y, vector<int> &xMove, vector<int> &yMove, int n, int move)
{
    if (move == n * n + 1)
    {
        return 1;
    }

    // try all move
    for (int i = 0; i < 8; i++)
    {
        int next_x = x + xMove[i];
        int next_y = y + yMove[i];
        if (isValid(board, n, next_x, next_y))
        {
            board[next_x][next_y] = move;
            if (solveKnightTour(board, next_x, next_y, xMove, yMove, n, move + 1))
            {
                return 1;
            }
            else
            {
                board[next_x][next_y] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    // knight tour problem
    int n = 8;
    // cin >> n;
    // print solution knight tour on nxn board
    vector<int> xMove = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> yMove = {1, 2, 2, 1, -1, -2, -2, -1};

    // initialize board
    vector<vector<int>> board(n, vector<int>(n, 0));
    int move = 1;
    board[0][0] = move;
    move++;
    // move until n x n board is filled
    // from number 1 .. n^2
    if (solveKnightTour(board, 0, 0, xMove, yMove, n, move))
    {
        // print board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution" << endl;
    }
    return 0;
}