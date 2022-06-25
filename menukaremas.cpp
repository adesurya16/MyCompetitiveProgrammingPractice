#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = max(arr[i / 2] + arr[i / 3] + arr[i / 4], i);
    }
    cout << arr[n] << endl;
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