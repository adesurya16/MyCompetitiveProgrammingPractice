// Longest Common Subsequence
//  ''abcdgh
//'' 0000000
// a 0111111
// e 0111111
// d 0......
// f 0......
// h 0......
// r 0......

#include <bits/stdc++.h>
using namespace std;

int lcsDP(vector<vector<int>> &dp, string s1, string s2, int i, int j)
{
    if (i == 0 || j == 0)
        return 0;
    if (dp[i - 1][j - 1] != -1)
        return dp[i - 1][j - 1];
    if (s1[i - 1] == s2[j - 1])
    {
        return 1 + lcsDP(dp, s1, s2, i - 1, j - 1);
    }
    else
    {
        dp[i - 1][j - 1] = max(lcsDP(dp, s1, s2, i - 1, j), lcsDP(dp, s1, s2, i, j - 1));
        return dp[i - 1][j - 1];
    }
}

int lcs1(string s1, string s2)
{
    // dp rekursif/top down
    int l1 = s1.length();
    int l2 = s2.length();
    vector<vector<int>> dp(l1, vector<int>(l2, -1));
    return lcsDP(dp, s1, s2, l1, l2);
}

int lcs2(string s1, string s2)
{
    // dp iteratif/fill table/bottom up
    int l1 = s1.length();
    int l2 = s2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[l1][l2];
}

void printDP(vector<vector<int>> &dp)
{
    int x = dp.size();
    int y = dp[0].size();
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << dp[i][j];
        }
        cout << endl;
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    string s1, s2;
    cin >> s1;
    cin >> s2;
    // cout << lcs1(s1, s2) << endl;
    cout << lcs2(s1, s2) << endl;
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