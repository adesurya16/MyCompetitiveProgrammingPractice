// https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/
#include <bits/stdc++.h>
using namespace std;

// 0, 1, 2, 3, 4, 5, 6. 7. 8. 9. 10
// 0. 0. 0. 0, 0, 1, 1, 1, 1, 1, 2,

long long calculateZeroOfFac(long long n)
{
    long long multipleFive = 5;
    long long res = 0;
    while (multipleFive <= n)
    {
        res += (n / multipleFive);
        multipleFive *= 5;
    }
    return res;
}

long long firstIndexFoundBS(long long left, long long right, int target)
{
    // if not found -1;
    long long firstIdx = -1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long countZero = calculateZeroOfFac(mid);
        // cout << left << " " << mid << " " << right << " " << countZero << " " << target << endl;
        if (countZero == target)
        {
            firstIdx = mid;
            right = mid - 1;
        }
        else if (countZero < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return firstIdx;
}

long long lastIndexFoundBS(long long left, long long right, int target)
{
    long long lastIdx = -1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long countZero = calculateZeroOfFac(mid);
        if (countZero == target)
        {
            lastIdx = mid;
            left = mid + 1;
        }
        else if (countZero < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return lastIdx;
}

int preimageSizeFZF(int k)
{
    // define calculate zero of factorial function
    long long left = 0;
    long long right = (long long)(k + 1) * 5; // make sure f(1e9) >= 1e9
    // do binary search
    long long firstIdx = firstIndexFoundBS(left, right, k);
    // cout << firstIdx << endl;
    if (firstIdx == -1)
        return 0;
    long long lastIdx = lastIndexFoundBS(left, right, k);
    // cout << lastIdx << endl;
    // first index found and last index found

    // handle not found

    // issue overflow int
    return lastIdx - firstIdx + 1;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    // cout << calculateZeroOfFac(n) << endl;
    cout << preimageSizeFZF(n) << endl;
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