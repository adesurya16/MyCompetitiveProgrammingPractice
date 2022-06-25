#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> dp(n);
    k = k + 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int tmp = 0;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            tmp = 1;
        else if (arr[i] * 2 > arr[i - 1])
        {
            tmp++;
        }
        else
        {
            if (tmp < k)
            {
                tmp = 1;
            }
            else
            {
                total += (tmp - k + 1);
                tmp = 1;
            }
        }
    }
    if (tmp >= k)
    {
        total += (tmp - k + 1);
    }
    cout << total << endl;
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