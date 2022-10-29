#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // north -> east -> south -> east

bool isValidIndex(int x, int y, int boundx, int boundy)
{
    return (x >= 0 && x < boundx) && (y >= 0 && y < boundy);
}

int dfs(vector<vector<int>> const &matrix, vector<vector<int>> &dp, int bx, int by, int x, int y)
{
    if (dp[x][y] != 0)
    {
        return dp[x][y];
    }
    else
    {
        int result = 1;
        int maxdp = 0;
        for (int i = 0; i < moves.size(); i++)
        {
            int newx = x + moves[i][0];
            int newy = y + moves[i][1];
            if (isValidIndex(newx, newy, bx, by) && matrix[newx][newy] > matrix[x][y])
            {
                maxdp = max(maxdp, dfs(matrix, dp, bx, by, newx, newy));
            }
        }
        dp[x][y] = result + maxdp;
        return dp[x][y];
    }
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    // graph no circuit / tree problem

    // basis recurrence if exist/visited or no neighboor (1)

    // using dfs + memoization

    // expected time complexity O(mxn) and space complexity O(mxn)

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxdp = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 0)
            {
                int res = dfs(matrix, dp, m, n, i, j);
            }
            maxdp = max(maxdp, dp[i][j]);
        }
    }
    return maxdp;
}
void solve(int cases = 1)
{
    // solve the problem here
    // link problem https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
    int n, m;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << longestIncreasingPath(matrix) << endl;
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