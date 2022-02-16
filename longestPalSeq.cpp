#include <bits/stdc++.h>
using namespace std;

void printdp(vector<vector<int>> dp)
{
    int size = dp.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int longestPalSubseq(string s)
{
    int size = s.length();
    vector<vector<int>> dp = vector(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 1; i < size; i++) // skip first iteration because init dp i == j
    {
        for (int j = i; j < size; j++)
        {
            int idxi = j - i;
            int idxj = j;
            if (s[idxi] == s[idxj])
            {
                dp[idxi][idxj] = 2 + dp[idxi + 1][idxj - 1];
            }
            else
            {
                dp[idxi][idxj] = max(dp[idxi + 1][idxj], dp[idxi][idxj - 1]);
            }
        }
    }
    printdp(dp);
    return dp[0][size - 1];
}

void solve(int cases = 1)
{
    // solve the problem here
    string s;
    cin >> s;
    cout << longestPalSubseq(s) << endl;
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