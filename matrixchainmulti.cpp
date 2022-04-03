// matrix chain multiplication problem using DP O(N^2) time and O(N^2) space complexity
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
#include <bits/stdc++.h>
using namespace std;
int matrixChainOrder(vector<int> arr, int left, int right)
{
    // bruteforce still overlapping
    // the time complexity follow catalan numbers O(2nCn/(n + 1))
    // O(1) space complexity
    if (left == right)
    {
        return 0;
    }
    int minVal = INT_MAX;

    for (int k = left; k < right; k++)
    {
        int val = matrixChainOrder(arr, left, k) + matrixChainOrder(arr, k + 1, right) + arr[left - 1] * arr[k] * arr[right];
        minVal = min(val, minVal);
    }
    return minVal;
}

int matrixChainOrderDP(vector<int> arr)
{
    // bruteforce using iterating DP (bottom up), solve the ooverlapping problem
    // time complexity O(n^3)
    // space complexity O(n^2)
    int n = arr.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    // loop 2D like triangle (0, 0) (1,1) ... (n - 1, n - 1), (0, 1) (1, 2) .. (n - 2, n - 1), .... , (0, n - 1)
    for (int x = 1; x < n; x++)
    {
        for (int y = 0; y < n - x; y++)
        {
            int i = y;
            int j = y + x;
            int minLocal = INT_MAX;
            for (int k = i; k < j; k++)
            {
                minLocal = min(minLocal, dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1]);
            }
            dp[i][j] = minLocal;
        }
    }
    return dp[0][n - 1];
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<pair<int, int>> matrixSize(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        matrixSize[i] = pair(a, b);
    }
    // pre processing
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++)
    {
        arr[i] = matrixSize[i].first;
    }
    arr[n] = matrixSize[n - 1].second;
    // print(arr);
    // cout << matrixChainOrder(arr, 1, n) << endl;
    cout << matrixChainOrderDP(arr) << endl;
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