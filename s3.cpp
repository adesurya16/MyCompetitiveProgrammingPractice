#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<bool>> &b)
{
    int x = b.size();
    int y = b[0].size();
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << (int)b[i][j];
        }
        cout << endl;
    }
}

bool isValidIndex(int x, int y, int boundx, int boundy)
{
    return (x >= 0 && x < boundx) && (y >= 0 && y < boundy);
}

bool isReachable(vector<vector<char>> &board, pair<int, int> &pStart, pair<int, int> &pFinish)
{
    // ignore # H and S
    int x = board.size();
    int y = board[0].size();

    vector<vector<bool>> board2(x, vector<bool>(y));
    // copy to boolean of board
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (board[i][j] == '.' || board[i][j] == 'H' || board[i][j] == 'S')
            {
                board2[i][j] = 1;
            }
            else
                board2[i][j] = 0;
        }
    }

    // printBoard(board2);

    vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // north -> east -> south -> east

    stack<pair<int, int>> s;
    pair<int, int> p = pStart;
    s.push(p);
    while (!s.empty())
    {
        pair<int, int> dummy = s.top(); // should be 1 value
        s.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = dummy.first + moves[i].first;
            int newY = dummy.second + moves[i].second;
            if (isValidIndex(newX, newY, x, y) && board2[newX][newY])
            {
                s.push({newX, newY});
            }
        }

        board2[dummy.first][dummy.second] = 0;
    }

    // printBoard(board2);
    return !board2[pFinish.first][pFinish.second];
}

void solve(int cases = 1)
{
    // solve the problem here

    // input

    int x, y;
    cin >> x >> y;
    pair<int, int> pHome, pSchool; // cordinate certesius home and school
    vector<vector<char>> board(x, vector<char>(y));
    vector<pair<int, int>> pointAns;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'H')
            {
                pHome = {i, j};
            }
            if (board[i][j] == 'S')
            {
                pSchool = {i, j};
            }
            if (board[i][j] == '.')
            {
                pointAns.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // north -> east -> south -> east

    // special case if cant block anywhere
    for (int i = 0; i < 4; i++)
    {
        int newX = pSchool.first + moves[i].first;
        int newY = pSchool.second + moves[i].second;
        if (isValidIndex(newX, newY, x, y) && newX == pHome.first && newY == pHome.second)
        {
            cout << -1 << endl;
            return;
        }
    }
    // int blocks = 0;

    // board[pSchool.first][pSchool.second] = '#';
    // for (int i = 0; i < 4; i++)
    // {
    //     int newX = pSchool.first + moves[i].first;
    //     int newY = pSchool.second + moves[i].second;
    //     pair<int, int> newP = {newX, newY};
    //     if (isValidIndex(newX, newY, x, y) && isReachable(board, pHome, newP))
    //     {
    //         blocks++;
    //         board[newX][newY] = '#';
    //     }
    // }

    // maximum build is 4

    // define function reachable
    // isReachable(vector<vector<char>> board, pair<int, int> p1, pair<int, int> p2);

    // brutoforce for 64C1 + 64C2 + 64C3 + 64C4

    int blocks = INT_MAX;

    // case 1 block
    for (int i = 0; i < pointAns.size(); i++)
    {
        board[pointAns[i].first][pointAns[i].second] = '#';
        if (!isReachable(board, pHome, pSchool))
        {
            blocks = min(1, blocks);
            // break;
            cout << blocks << endl;
            return;
        }
        board[pointAns[i].first][pointAns[i].second] = '.';
    }

    // case 2 block
    for (int i = 0; i < pointAns.size() - 1; i++)
    {
        board[pointAns[i].first][pointAns[i].second] = '#';
        for (int j = i + 1; j < pointAns.size(); j++)
        {
            board[pointAns[j].first][pointAns[j].second] = '#';
            if (!isReachable(board, pHome, pSchool))
            {
                blocks = min(2, blocks);
                cout << blocks << endl;
                return;
            }
            board[pointAns[j].first][pointAns[j].second] = '.';
        }
        board[pointAns[i].first][pointAns[i].second] = '.';
    }

    // // case 3 block
    for (int i = 0; i < pointAns.size() - 2; i++)
    {
        board[pointAns[i].first][pointAns[i].second] = '#';
        for (int j = i + 1; j < pointAns.size() - 1; j++)
        {
            board[pointAns[j].first][pointAns[j].second] = '#';
            for (int k = j + 1; k < pointAns.size(); k++)
            {
                board[pointAns[k].first][pointAns[k].second] = '#';
                if (!isReachable(board, pHome, pSchool))
                {
                    blocks = min(3, blocks);
                    cout << blocks << endl;
                    return;
                }
                board[pointAns[k].first][pointAns[k].second] = '.';
            }
            board[pointAns[j].first][pointAns[j].second] = '.';
        }
        board[pointAns[i].first][pointAns[i].second] = '.';
    }

    // // case 4 block
    for (int i = 0; i < pointAns.size() - 3; i++)
    {
        board[pointAns[i].first][pointAns[i].second] = '#';
        for (int j = i + 1; j < pointAns.size() - 2; j++)
        {
            board[pointAns[j].first][pointAns[j].second] = '#';
            for (int k = j + 1; k < pointAns.size() - 1; k++)
            {
                board[pointAns[k].first][pointAns[k].second] = '#';
                for (int l = k + 1; l < pointAns.size(); l++)
                {
                    board[pointAns[l].first][pointAns[l].second] = '#';
                    if (!isReachable(board, pHome, pSchool))
                    {
                        blocks = min(4, blocks);
                        cout << blocks << endl;
                        return;
                    }
                    board[pointAns[l].first][pointAns[l].second] = '.';
                }

                board[pointAns[k].first][pointAns[k].second] = '.';
            }
            board[pointAns[j].first][pointAns[j].second] = '.';
        }
        board[pointAns[i].first][pointAns[i].second] = '.';
    }

    cout << blocks << endl;
}

int main()
{
    solve();
    return 0;
}