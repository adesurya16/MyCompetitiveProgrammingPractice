#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    // nums is rotated array (array is unique)
    // time complexity O(Log N)
    int size = nums.size();
    int low = 0, high = size - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) // because array is unique
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return nums[low];
}

void solve(int cases = 1)
{
    // solve the problem here
    // input: n
    int n;
    cin >> n;
    vector<int> v(n);
    // input rotated array ex : 4 5 6 7 0 1 2 from increasing array 0 1 2 3 4 5 6 7 return 0
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << findMin(v) << endl;
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