#include <bits/stdc++.h>
using namespace std;
#define fastIO() \
    ;            \
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
int bSearch(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target <= arr[mid])
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
        {
            arr[i] = arr[i] + arr[i - 1];
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int order;
        cin >> order;
        int idx = bSearch(arr, order);
        cout << idx + 1 << endl;
    }
}

int main()
{
    fastIO();
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}