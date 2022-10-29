#include <bits/stdc++.h>
using namespace std;
bool isValidIndex(int x, int y, int boundx, int boundy)
{
    return (x >= 0 && x < boundx) && (y >= 0 && y < boundy);
}

bool isReachable(vector<vector<int>> &adj, int idStart, int idFinish)
{
    queue<int> q;
    set<int> visited;
    q.push(idStart); // id in queue always not visited
    while (!q.empty())
    {
        int idTop = q.front();
        if (idTop == idFinish)
            return 1;
        q.pop();
        for (int id : adj[idTop])
        {
            if (visited.find(id) == visited.end())
            {
                q.push(id);
            }
        }

        visited.insert(idTop);
    }
    return 0;
}

void solve(int cases = 1)
{
    // solve the problem here
    int x, y;
    cin >> x >> y;
    vector<vector<char>> board(x, vector<char>(y));
    pair<int, int> ss, ff;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'H')
            {
                ss = {i, j};
            }
            if (board[i][j] == 'S')
            {
                ff = {i, j};
            }
        }
    }

    vector<vector<int>> boardId(x, vector<int>(y));
    int id = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (board[i][j] == '#')
            {
                boardId[i][j] = -1;
            }
            else
            {
                boardId[i][j] = id;
                id++;
            }
        }
    }
    int sizeId = id;

    // print representation of the graph
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (j > 0)
                cout << " ";
            cout << boardId[i][j];
        }
        cout << endl;
    }

    vector<pair<int, int>> moves = {{-1, 0},
                                    {0, -1},
                                    {0, 1},
                                    {1, 0}}; // atas kiri kanan bawah

    // create adjentcy list from the grid/matrix
    vector<vector<int>> adjList(sizeId, vector<int>());

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (boardId[i][j] != -1)
            {
                int currentId = boardId[i][j];
                vector<int> nb;
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + moves[k].first, nj = j + moves[k].second;
                    if (isValidIndex(ni, nj, x, y) && boardId[ni][nj] != -1)
                    {
                        nb.push_back(boardId[ni][nj]);
                    }
                }
                adjList[currentId] = nb;
            }
        }
    }

    // print adjency list
    // for (int i = 0; i < sizeId; i++)
    // {
    //     int len = adjList[i].size();
    //     cout << i;
    //     for (int j = 0; j < len; j++)
    //     {
    //         cout << " " << adjList[i][j];
    //     }
    //     cout << endl;
    // }

    if (isReachable(adjList, boardId[ss.first][ss.second], boardId[ff.first][ff.second]))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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