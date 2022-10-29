#include <bits/stdc++.h>
using namespace std;

pair<int, int> subArrSum(vector<int> &arr, int sum)
{
    int curr_sum = 0;
    int n = arr.size();
    map<int, int> mapSum;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        // cout << curr_sum << endl;
        if (curr_sum == sum)
            return {0, i};
        if (mapSum.find(curr_sum - sum) != mapSum.end())
        {
            return {mapSum[curr_sum - sum] + 1, i};
        }
        mapSum[curr_sum] = i;
    }
    return {-1, -1};
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    pair<int, int> res = subArrSum(arr, sum);
    cout << res.first << " " << res.second << endl;
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