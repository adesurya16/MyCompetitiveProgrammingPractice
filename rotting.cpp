#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/rotting-oranges/

void printQ(queue<pair<int, int>> q)
{
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        cout << "{" << p.first << " " << p.second << "} ";
    }
    cout << endl;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int x = grid.size();
    int y = grid[0].size();
    int sumRotten = 0;
    int sumFresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (grid[i][j] == 1)
            {
                sumFresh++;
            }
            else if (grid[i][j] == 2)
            {
                sumRotten++;
                q.push({i, j});
            }
        }
    }
    // cout << sumRotten << " " << sumFresh << endl;
    // printQ(q);
    // cout << endl;

    vector<int> dirX = {1, 0, -1, 0};
    vector<int> dirY = {0, 1, 0, -1};
    set<pair<int, int>> s;
    // init
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        pair<int, int> p = q.front();
        s.insert({p.first, p.second});
        q.pop();
        for (int j = 0; j < 4; j++)
        {
            int newX = p.first + dirX[j];
            int newY = p.second + dirY[j];
            if (newX >= 0 && newX < x && newY >= 0 && newY < y && grid[newX][newY] == 1 && s.find({newX, newY}) == s.end())
            {
                s.insert({newX, newY});
                q.push({newX, newY});
            }
        }
    }

    // printQ(q);
    // cout << endl;

    int step = 0;
    while (!q.empty())
    {
        step++;
        int size = q.size();
        // cout << sumRotten << " " << sumFresh << endl;
        // printQ(q);
        // cout << endl;
        for (int i = 0; i < size; i++)
        {
            pair<int, int> p = q.front();
            q.pop();
            if (grid[p.first][p.second] == 1)
            {
                grid[p.first][p.second] = 2;
                sumRotten++;
                sumFresh--;
                for (int j = 0; j < 4; j++)
                {
                    int newX = p.first + dirX[j];
                    int newY = p.second + dirY[j];
                    if (newX >= 0 && newX < x && newY >= 0 && newY < y && grid[newX][newY] == 1 && s.find({newX, newY}) == s.end())
                    {
                        s.insert({newX, newY});
                        q.push({newX, newY});
                    }
                }
            }
        }
    }
    if (sumFresh > 0)
        return -1;
    else
        return step;
}

void solve(int cases = 1)
{
    // solve the problem here
    // 0 -> empty cell
    // 1 -> fresh orangewater
    // 2 -> rotten orange
    int x, y;
    cin >> x >> y;
    vector<vector<int>> arr = vector(x, vector<int>(y, 0));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << orangesRotting(arr) << endl;
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