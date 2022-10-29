// https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
#include <bits/stdc++.h>
using namespace std;

int maximumSubarrayLessThanEqualK(vector<int> &arr, int k)
{
    return 0;
}

void solve(int cases = 1)
{
    // solve the problem here
    // given array size of n

    // can be negative, zero , positive numbers
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // given k
    int k;
    cin >> k;

    vector<int> prefixSum(n);
    int sum = 0;
    set<int> setSum;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        prefixSum[i] = sum;
        setSum.insert(sum);
        cout << sum << " ";
    }
    cout << endl;

    // to set
    cout << *setSum.lower_bound(k) << endl;

    cout << *setSum.upper_bound(k) << endl;

    // find sum of subsequence/continue subarray less than or equal k

    // cout << maximumSubarrayLessThanEqualK() << endl;
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