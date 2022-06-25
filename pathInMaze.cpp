#include <bits/stdc++.h>
using namespace std;
bool isValid(int x, int y, vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();
    // cout << "valid" << endl;
    // cout << x << " " << y << endl;
    // cout << m << " " << n << endl;
    return x >= 0 && x < m && y >= 0 && y < n && board[x][y] == '.';
}

void maze(vector<vector<char>> &board, vector<int> &xMove, vector<int> &yMove, int x, int y, int xTarget, int yTarget, int move, int &minMove)
{
    if (x == xTarget && y == yTarget)
    {
        // cout << "target" << endl;
        minMove = min(minMove, move);
    }
    else if (isValid(x, y, board))
    {
        move++;
        board[x][y] = '#';
        for (int i = 0; i < 4; i++)
        {
            // cout << "i : " << i << endl;
            int next_x = x + xMove[i];
            int next_y = y + yMove[i];
            // cout << "next_x: " << next_x << " next_y: " << next_y << endl;
            maze(board, xMove, yMove, next_x, next_y, xTarget, yTarget, move, minMove);
        }
        board[x][y] = '.';
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    int xStart = 0, yStart = 0, xEnd = 0, yEnd = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j]; //. or # or S or T
            if (board[i][j] == 'S')
            {
                xStart = i;
                yStart = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'T')
            {
                xEnd = i;
                yEnd = j;
            }
        }
    }
    // cout << xStart << " " << yStart << " " << xEnd << " " << yEnd << endl;
    vector<int> xMove = {1, 0, -1, 0};
    vector<int> yMove = {0, 1, 0, -1};
    int minPath = INT_MAX;
    int move = 0;
    // call method maze
    maze(board, xMove, yMove, xStart, yStart, xEnd, yEnd, move, minPath);
    if (minPath == INT_MAX)
    {
        cout << "DOOMED" << endl;
    }
    else
        cout << minPath << endl;
}

int main()
{
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}