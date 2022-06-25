#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int binarySearchFirstFound(vector<int> &arr, int left, int right, int target)
{
    int index = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            index = mid;
            right = mid - 1;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return index;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    int sum = 0;
    vector<int> prefixSum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        prefixSum[i] = sum;
    }
    int ans = -1;
    if (sum < s)
    {
        cout << -1 << endl;
        return;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << prefixSum[i] << " ";
    // }
    // cout << endl;

    for (int i = n - 1; i >= 0; i--)
    {
        int target = prefixSum[i] - s;

        if (target == 0)
        {
            // cout << target << " " << -1 << endl;
            ans = max(ans, i + 1);
        }
        else if (target > 0)
        {
            int index = binarySearchFirstFound(prefixSum, 0, i - 1, target);
            if (index != -1)
            {
                // cout << target << " " << index << endl;
                ans = max(ans, i - index);
            }
        }
    }
    cout << n - ans << endl;
}

int main()
{
    // fast IO
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}