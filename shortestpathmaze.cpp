// shortest path maze
// S = point start
// 1 = available point
// 0 = unavailable point
// F = point finish
#include <bits/stdc++.h>
using namespace std;
bool isValid(pair<int, int> p, vector<vector<char>> const &board, vector<vector<bool>> const &bVisited)
{
    int row = board.size();
    int column = board[0].size();
    int x = p.first;
    int y = p.second;
    return (x >= 0 && x < row) && (y >= 0 && y < column) && board[x][y] != '0' && !bVisited[x][y];
}

//    solveShortestPathMaze(pStart, pFinish, board, bVisited, move, moves, res);
void solveShortestPathMaze(pair<int, int> p, pair<int, int> const &target, vector<vector<char>> const &board, vector<vector<bool>> &bVisited, int move, vector<pair<int, int>> const &moves, int &res)
{
    if (isValid(p, board, bVisited))
    {
        move++;
        if (p == target)
        {
            if (res == -1)
                res = move;
            else
                res = min(res, move);
        }
        else
        {
            bVisited[p.first][p.second] = 1; // visit
            for (int i = 0; i < moves.size(); i++)
            {
                pair<int, int> pNext = make_pair(p.first + moves[i].first, p.second + moves[i].second);
                solveShortestPathMaze(pNext, target, board, bVisited, move, moves, res);
            }
            bVisited[p.first][p.second] = 0; // backtrack
        }
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    int row, column;
    cin >> row >> column;
    pair<int, int> pStart, pFinish;
    vector<vector<char>> board(row, vector<char>(column));
    vector<vector<bool>> bVisited(row, vector<bool>(column, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
            {
                pStart = make_pair(i, j);
                board[i][j] = '1';
            }
            if (board[i][j] == 'F')
            {
                pFinish = make_pair(i, j);
                board[i][j] = '1';
            }
        }
    }
    // right, down, left, up
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int res = -1;
    int move = 0;
    solveShortestPathMaze(pStart, pFinish, board, bVisited, move, moves, res);
    cout << res << endl;
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