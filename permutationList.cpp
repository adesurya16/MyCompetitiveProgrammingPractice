#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void printRes(vector<vector<int>> &res)
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            if (j == 0)
                cout << res[i][j];
            else
                cout << ", " << res[i][j];
        }
        cout << "]" << endl;
    }
}

void printArr(vector<int> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
            cout << arr[i];
        else
            cout << ", " << arr[i];
    }
    cout << "]" << endl;
}

void permutation(int left, int right, vector<int> &arr)
{
    if (left == right)
    {
        res.push_back(arr);
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(arr[left], arr[i]);
            permutation(left + 1, right, arr);
            swap(arr[left], arr[i]);
        }
    }
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
    permutation(0, n - 1, arr);
    printRes(res);
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