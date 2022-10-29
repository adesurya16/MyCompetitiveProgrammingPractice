#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int mod = 1e9 + 7;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }
    // for (int i = 0; i < m; i++)
    // {

    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<long long>> step(m, vector<long long>(n, 0));
    step[0][0] = 1;
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                step[i][j] = 1;
            }
            else if (grid[i][j] == 1)
            {
                long long left = 0;
                if ((i > 0) && (grid[i - 1][j] == 1))
                {
                    left = step[i - 1][j] % mod;
                }
                long long up = 0;
                if ((j > 0) && (grid[i][j - 1] == 1))
                {
                    up = step[i][j - 1] % mod;
                }
                step[i][j] = (left + up) % mod;
            }
            // cout << step[i][j] << " ";
        }
        // cout << endl;
    }
    cout << step[m - 1][n - 1] << endl;
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