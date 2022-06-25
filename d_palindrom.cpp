#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    // longest Palindrom Subsequence Problem
    string s;
    cin >> s;
    int len = s.size();
    vector<vector<int>> dp = vector<vector<int>>(len, vector<int>(len, 0));

    // looping
    // ex len = 5
    // {0, 0} {1, 1} {2, 2} {3, 3} {4, 4}
    // {0, 1} {1, 2} {2, 3} {3, 4}
    // {0, 2} {1, 3} {2, 4}
    // {0, 3} {1, 4}
    // {0, 4}

    // if (i == j) return 1;
    // if (i > j) return 0;
    // if s[i] == s[j] return dp[i+1][j-1] + 2;
    // if s[i] != s[j] return max(dp[i+1][j], dp[i][j-1]);
    int maxLen = 0;
    for (int k = 0; k < len; k++)
    {
        for (int l = 0; l < len - k; l++)
        {
            int i = l;
            int j = l + k;
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (s[i] == s[j])
            {
                if (i + 1 > j - 1)
                {
                    dp[i][j] = 2;
                }
                else
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    cout << maxLen << endl;
}

int main()
{
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}