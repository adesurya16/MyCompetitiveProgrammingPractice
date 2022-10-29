#include <bits/stdc++.h>
using namespace std;

int levenstheinDP(vector<vector<int>> &dp, string s1, string s2, int i, int j)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i - 1][j - 1] != -1)
        return dp[i - 1][j - 1];
    if (s1[i - 1] == s2[j - 1])
    {
        return levenstheinDP(dp, s1, s2, i - 1, j - 1);
    }
    else
    {
        dp[i - 1][j - 1] = 1 + min(levenstheinDP(dp, s1, s2, i - 1, j), min(levenstheinDP(dp, s1, s2, i, j - 1), levenstheinDP(dp, s1, s2, i - 1, j - 1)));
        return dp[i - 1][j - 1];
    }
}

int levensthein1(string s1, string s2)
{
    // dp rekursif/top down
    int l1 = s1.length();
    int l2 = s2.length();
    vector<vector<int>> dp(l1, vector<int>(l2, -1));
    return levenstheinDP(dp, s1, s2, l1, l2);
}

int levensthein2(string s1, string s2)
{
    // dp iteratif/fill table/bottom up
    int l1 = s1.length();
    int l2 = s2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
    // init dp when length(l1) == 0
    for (int i = 0; i <= l1; i++)
    {
        dp[i][0] = i;
    }
    // init dp when length(l2) == 0
    for (int i = 0; i <= l2; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[l1][l2];
}

void solve(int cases = 1)
{
    // solve the problem here
    // given two strings, find the edit distance/ levensthein distance between them
    // edit distance/levensthein is the minimum number of operations needed to transform one string into another
    // operations include: insert, delete, replace
    string str1, str2;
    cin >> str1;
    cin >> str2;
    // cout << levensthein1(str1, str2) << endl;
    cout << levensthein2(str1, str2) << endl;
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