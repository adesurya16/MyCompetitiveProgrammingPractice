#include <bits/stdc++.h>
using namespace std;
void printSolution(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int x, int y, vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();
    return x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1;
}

bool solveMaze(vector<vector<int>> &board, vector<vector<int>> &sol, int x, int y, int xTarget, int yTarget, vector<int> &xMove, vector<int> &yMove)
{
    if (x == xTarget && y == yTarget)
    {
        sol[x][y] = 1;
        return 1;
    }
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + xMove[i];
        int next_y = y + yMove[i];
        if (isValid(next_x, next_y, board))
        {
            board[next_x][next_y] = 0;
            if (solveMaze(board, sol, next_x, next_y, xTarget, yTarget, xMove, yMove))
            {
                sol[next_x][next_y] = 1;
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
    // maze problem isReach Or Not using backtracking
    int m = 4;
    int n = 5;
    // cin >> n;
    vector<vector<int>> board(m, vector<int>(n, 0));
    vector<vector<int>> solution(m, vector<int>(n, 0));
    vector<int> xMove = {1, 0, -1, 0};
    vector<int> yMove = {0, 1, 0, -1};
    board = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}};
    // printSolution(board);
    cout << endl;
    // board[x][y] = 1 means it is a valid point to move
    // board[x][y] = 0 means it is a invalid point to move
    int xStart = 0, yStart = 0;
    int xEnd = 3, yEnd = 4;
    solution[0][0] = 1;
    if (solveMaze(board, solution, xStart, yStart, xEnd, yEnd, xMove, yMove))
    {
        printSolution(solution);
    }
    else
    {
        cout << "No Solution" << endl;
    }
    return 0;
}