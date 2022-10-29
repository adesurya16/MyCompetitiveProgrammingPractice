// gas station leetcode problem
#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    vector<int> dp(n);
    // idx [0,  n-1]
    for (int i = 0; i < n; i++)
    {
        dp[i] = gas[i] - cost[i];
    }
    // printArr(dp);
    int idx = 0; // 0..n-1, n, n + 1, ... 2*n - 2
    int currentSum = 0;
    while (idx <= (2 * (n - 1)))
    {
        currentSum = 0;
        int start = idx;
        // cout << "start : ";
        // cout << start << endl;
        for (int i = 0; i <= n - 1; i++)
        {
            if (idx + i > (2 * (n - 1)))
                return -1;
            currentSum += dp[(idx + i) % n];
            if (currentSum < 0)
            {
                idx = idx + i;
                break;
            }
        }
        // cout << "currentSum : ";
        // cout << currentSum << endl;
        if (currentSum >= 0)
            return start;
        idx++;
    }
    return -1;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> gas[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    cout << canCompleteCircuit(gas, cost) << endl;
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