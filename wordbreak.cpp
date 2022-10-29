#include <bits/stdc++.h>
using namespace std;
bool isSubStr(string str, int currentIdx, string subStr)
{
    for (int i = subStr.size() - 1; i >= 0; i--)
    {
        if (currentIdx < 0)
            return 0;
        if (str[currentIdx] != subStr[i])
        {
            return 0;
        }
        currentIdx--;
    }
    return 1;
}

void printDP(vector<bool> dp)
{
    for (auto i : dp)
    {
        cout << i;
    }
    cout << endl;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    // dp bottom up (table iteration)
    // expected time complexity O(n x m), n = size of s, m size of wordict
    // using 1D array
    int m = wordDict.size();
    int n = s.size();
    vector<bool> dp(n + 1, 0);
    dp[0] = 1;
    // for (int i = 0; i < m; i++)
    // {
    //     string subStr = wordDict[i];
    //     int len = subStr.size();
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (isSubStr(s, j - 1, subStr))
    //         {
    //             dp[j] = dp[j - len] || dp[j];
    //         }
    //     }
    // }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            string subStr = wordDict[i];
            int len = subStr.size();
            if (isSubStr(s, j - 1, subStr))
            {
                dp[j] = dp[j - len] || dp[j];
            }
        }
    }

    // printDP(dp);
    return dp[n];
}

void solve(int cases = 1)
{
    // solve the problem here
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (wordBreak(s, arr))
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
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