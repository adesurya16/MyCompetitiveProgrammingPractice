#include <bits/stdc++.h>
using namespace std;
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool checkSubarraySum(vector<int> nums, int k)
{
    // prefix table of remainder
    int n = nums.size();
    vector<int> table(n);
    map<int, int> mapNums;
    // int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            table[i] = nums[i] % k;
        }
        else
        {
            table[i] = (table[i - 1] + nums[i] % k) % k;
        }
        mapNums[table[i]]++;
    }

    // cout << "table : ";
    // print(table);

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && table[i] == 0)
            return true;
        if ((i < n && table[i + 1] == table[i] && mapNums[table[i]] > 2) || (i < n && table[i + 1] != table[i] && mapNums[table[i]] > 1))
            return true;
        mapNums[table[i]]--;
    }
    return false;
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
    int k;
    cin >> k;
    cout << checkSubarraySum(arr, k) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}