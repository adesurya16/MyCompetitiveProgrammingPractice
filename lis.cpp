// longest inscreasing subsequence problem
#include <bits/stdc++.h>
using namespace std;
int LIS(vector<int> &v)
{
    // time complexity O(N^2)
    // space complexity O(N)
    int size = v.size();
    vector<int> dp(size, 1);
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << LIS(v) << endl;
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