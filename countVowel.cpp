// https://leetcode.com/problems/count-vowels-permutation/
// dp problem
#include <bits/stdc++.h>
using namespace std;

int sumArr(vector<int> &arr, int modulo)
{
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res = (res + arr[i]) % modulo;
    }
    return res;
}

int countVowelPermutation(int n)
{
    // O(n) time and O(1) space
    int modulo = 1e9 + 7;
    int a = 0, i = 1, u = 2, e = 3, o = 4;
    vector<vector<int>> dp(2, vector<int>(5, 0));
    dp[0][a] = 1;
    dp[0][i] = 1;
    dp[0][u] = 1;
    dp[0][e] = 1;
    dp[0][o] = 1;
    // flaying table dp bottom up iteration
    for (int idx = 1; idx < n; idx++)
    {
        if (idx % 2 == 0)
        {
            dp[0][a] = (((dp[1][e] + dp[1][u]) % modulo) + dp[1][i]) % modulo;
            dp[0][i] = (dp[1][e] + dp[1][o]) % modulo;
            dp[0][u] = (dp[1][i] + dp[1][o]) % modulo;
            dp[0][e] = (dp[1][a] + dp[1][i]) % modulo;
            dp[0][o] = dp[1][i] % modulo;
        }
        else
        {
            dp[1][a] = (((dp[0][e] + dp[0][u]) % modulo) + dp[0][i]) % modulo;
            dp[1][i] = (dp[0][e] + dp[0][o]) % modulo;
            dp[1][u] = (dp[0][i] + dp[0][o]) % modulo;
            dp[1][e] = (dp[0][a] + dp[0][i]) % modulo;
            dp[1][o] = dp[0][i] % modulo;
        }
    }
    return sumArr(dp[(n - 1) % 2], modulo);
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    cout << countVowelPermutation(n) << endl;
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