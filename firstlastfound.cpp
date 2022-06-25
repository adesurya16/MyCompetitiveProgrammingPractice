#include <bits/stdc++.h>
using namespace std;
int binarySearchFirstOccurrance(int left, int right, vector<int> &arr, int target)
{
    int firstFound = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            firstFound = mid;
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
    return firstFound;
}

int binarySearchLastOccurrance(int left, int right, vector<int> &arr, int target)
{
    int lastFound = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            lastFound = mid;
            left = mid + 1;
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
    return lastFound;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int target;
    cin >> target;

    // find first occurance
    int firstOccurrance = binarySearchFirstOccurrance(0, n - 1, arr, target);

    // find last occurance
    int lastOccurrance = binarySearchLastOccurrance(0, n - 1, arr, target);

    cout << firstOccurrance << " " << lastOccurrance << endl;
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