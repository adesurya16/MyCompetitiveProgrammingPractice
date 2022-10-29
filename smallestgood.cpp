#include <bits/stdc++.h>
using namespace std;

int calculateBaseRep(long long num, long long base, int loop)
{
    // return -1, 0 or 1
    int k = 1;
    for (int i = 0; i < loop; i++)
    {
        num -= k;
        k *= base;
    }
    if (num > 0)
    {
        return 1;
    }
    else if (num < 0)
    {
        return -1;
    }
    else
        return 0;
}

string smallestGoodBase(string n)
{
    // string to long long
    long long num = stoll(n);

    // looping between[63,2]
    for (int i = 63; i >= 2; i--) // try from 63's 1... to 2's 1...
    {
        // binary search
        long long low = 2;
        long long high = 10e18 - 1;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2; // base candidate
            int mark = calculateBaseRep(num, mid, i);
            if (mark == 0)
            {
                // always reach here
                return to_string(mid);
            }
            else if (mark == 1)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return "11";
}

void solve(int cases = 1)
{
    // solve the problem here
    // smallest good base problem
    // https://leetcode.com/problems/smallest-good-base/
    // calculate base where base^n = 1 or 11 or 11 or ...
    string num;
    cin >> num;
    cout << smallestGoodBase(num) << endl;
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