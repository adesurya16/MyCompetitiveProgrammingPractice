#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}; // from north to the north west follow clockwise direction

bool isValid(int x, int y, int bX, int bY)
{
    return (x >= 0) && (x < bX) && (y >= 0) && (y < bY);
}

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    // create the adjacency list
    int m = grid.size();
    int n = grid[0].size();
    if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
        return -1;
    int idx = 0;
    vector<vector<int>> matId(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                matId[i][j] = idx;
                idx++;
            }
        }
    }

    // create adjacency list
    vector<vector<int>> adjList(idx, vector<int>());
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matId[i][j] != -1)
            {
                int id = matId[i][j];
                // fill the neighboors
                for (int k = 0; k < 8; k++)
                {
                    int newX = i + dir[k].first;
                    int newY = j + dir[k].second;
                    if (isValid(newX, newY, m, n) && matId[newX][newY] != -1)
                    {
                        adjList[id].push_back(matId[newX][newY]);
                    }
                }
            }
        }
    }

    // BFS shortest path as adjacency list

    set<int> visited;
    int start = matId[0][0];
    int finish = matId[m - 1][n - 1];
    queue<pair<int, int>> q;
    q.push({start, 0});

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        int id = node.first;
        int currPath = node.second + 1;
        if (id == finish)
        {
            return currPath;
        }
        if (visited.find(id) == visited.end())
        {
            visited.insert(id);
            for (int neighboor : adjList[id])
            {
                q.push({neighboor, currPath});
            }
        }
    }
    return -1;
}



vector<vector<int>> transposeMat(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> grids(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grids[i][j] = (int)(grid[i][j] == '1');
        }
    }
    return grids;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n, m;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> grids = transposeMat(grid);
    cout << shortestPathBinaryMatrix(grids) << endl;
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