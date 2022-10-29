#include <bits/stdc++.h>
using namespace std;
vector<int> closestNumbers(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    // find smallest (greedy)
    int n = arr.size();
    int smallest = INT_MAX;
    for (int i = 0; i <= n - 2; i++)
    {
        smallest = min(smallest, abs(arr[i] - arr[i + 1]));
    }
    vector<int> res;
    for (int i = 0; i <= n - 2; i++)
    {
        if (abs(arr[i] - arr[i + 1]) == smallest)
        {
            res.push_back(arr[i]);
            res.push_back(arr[i + 1]);
        }
    }
    return res;
}

void printArr(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << arr[i];
    }
    cout << endl;
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
    printArr(closestNumbers(arr));
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