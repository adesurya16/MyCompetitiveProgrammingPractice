#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> lMax(n), rMax(n);
    lMax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        lMax[i] = max(lMax[i - 1], height[i]);
    }
    rMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rMax[i] = max(rMax[i + 1], height[i]);
    }
    int trap = 0;
    for (int i = 0; i < n; i++)
    {
        int h = min(rMax[i], lMax[i]);
        if (height[i] < h)
            trap += (h - height[i]);
    }
    return trap;
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
    cout << trap(arr) << endl;
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