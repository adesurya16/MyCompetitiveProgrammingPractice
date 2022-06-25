#include <bits/stdc++.h>
using namespace std;
int maxIndexArr(int left, int right, vector<int> arr)
{
    int maxNumber = 0;
    int idx = -1;
    for (int i = left; i <= right; i++)
    {
        if (arr[i] > maxNumber)
        {
            maxNumber = arr[i];
            idx = i;
        }
    }
    return idx;
}

void heightEachNode(int left, int right, vector<int> arr, vector<int> &ans, int height)
{
    if (left <= right)
    {
        int mid = maxIndexArr(left, right, arr);
        ans[mid] = height;
        heightEachNode(left, mid - 1, arr, ans, height + 1);
        heightEachNode(mid + 1, right, arr, ans, height + 1);
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> ans(n);
    heightEachNode(0, n - 1, arr, ans, 0);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
    // cout << heightTree(0, n - 1, arr) << endl;
}

int main()
{
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}