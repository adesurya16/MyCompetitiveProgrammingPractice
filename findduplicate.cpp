#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    int ptr = arr[0];
    while (ptr != slow)
    {
        ptr = arr[ptr];
        slow = arr[slow];
    }
    return ptr;
}

void solve(int cases = 1)
{
    // solve the problem here
    // find duplicate problem
    // using Floyd's Tortoise and Hare Algorithm

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findDuplicate(arr) << endl;
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