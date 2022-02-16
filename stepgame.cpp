#include <bits/stdc++.h>
using namespace std;
int kadaneMin(vector<int> arr);
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

    // kadane alghorithm minimum value
    cout << kadaneMin(arr) << endl;
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

int kadaneMin(vector<int> arr)
{
    int minArr = INT_MAX;
    int currentMin = 0;
    int minAllPos = INT_MAX;
    bool isAllPositive = true;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
            isAllPositive = false;
        minAllPos = min(minAllPos, arr[i]);
        currentMin = min(arr[i], currentMin + arr[i]);
        minArr = min(currentMin, minArr);
    }
    if (isAllPositive)
        return minAllPos;
    return minArr;
}