#include <bits/stdc++.h>
using namespace std;

int digitDP(vector<vector<vector<int>>> &dp, string &num, int n, int ctr, bool isTight)
{
    if (n == num.size())
        return ctr;
    if (dp[n][ctr][isTight] != -1)
        return dp[n][ctr][isTight];
}

int countDigitOne(int n)
{
    string s = to_string(n);
    vector<vector<vector<int>>> dp() // digit dp representation init all -1
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    cout << countDigitOne(n) << endl;
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