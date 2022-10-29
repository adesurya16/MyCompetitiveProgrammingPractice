#include <bits/stdc++.h>
using namespace std;
// candy problem from leetcode
int candy(vector<int> &ratings)
{
    // left to right
    // right to left
    int n = ratings.size();
    vector<int> dpLeft(n, 1), dpRight(n, 1);
    // left to right
    for (int i = 1; i <= n - 1; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            dpLeft[i] = dpLeft[i - 1] + 1;
        }
    }

    // right to left
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            dpRight[i] = dpRight[i + 1] + 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += max(dpLeft[i], dpRight[i]);
    }
    return sum;
}
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << candy(arr) << endl;
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