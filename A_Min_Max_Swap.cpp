#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> arr1, arr2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr1.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr2.push_back(x);
    }

    int maxArr1 = INT_MIN; // all max
    int maxArr2 = INT_MIN; // all min
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] > arr2[i])
        {
            maxArr1 = max(maxArr1, arr1[i]);
            maxArr2 = max(maxArr2, arr2[i]);
        }
        else
        {
            maxArr1 = max(maxArr1, arr2[i]);
            maxArr2 = max(maxArr2, arr1[i]);
        }
        // cout << maxArr1 << " " << maxArr2 << endl;
    }
    // sort(arr.begin(), arr.end());
    // cout << arr[n - 1] * arr[2 * n - 1] << endl;
    cout << maxArr1 * maxArr2 << endl;
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