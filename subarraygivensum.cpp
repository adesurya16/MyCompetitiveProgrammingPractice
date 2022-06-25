#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, long long s)
{
    int left = 0;
    int right = 0;
    long long sum = 0;
    while (left < n)
    {
        if (sum == s)
        {
            vector<int> res;
            res.push_back(left + 1);
            res.push_back(right);
            return res;
        }
        else if (left == right || sum < s)
        {
            sum += arr[right];
            right++;
        }
        else
        {
            sum -= arr[left];
            left++;
        }
    }
    vector<int> res;
    res.push_back(-1);
    return res;
}

vector<int> subarraySum2(int arr[], int n, long long s)
{
    int pLeft = 0;
    int pRight = 1;
    long long sum = arr[0];
    
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    long long s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // vector<int> res = subarraySum(arr, n, s);
    vector<int> res = subarraySum2(arr, n, s);
    if (res.size() == 1)
    {
        cout << res[0] << endl;
    }
    else
    {
        cout << res[0] << " " << res[1] << endl;
    }
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