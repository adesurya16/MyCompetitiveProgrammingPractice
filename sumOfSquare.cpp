#include <bits/stdc++.h>
using namespace std;
bool judgeSquareSum(int c)
{
    int limit = sqrt(c / 2);
    for (int i = 0; i <= limit; i++)
    {
        int j = sqrt(c - i * i);
        if (j * j == c - i * i)
        {
            return true;
        }
    }
    return false;
}

bool judgeSquareSum2(int c)
{
    int limit = sqrt((double)c / 2);
    int left = 1;
    int right = limit;
    cout << limit << endl;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int j = sqrt(c - mid * mid);
        // cout << mid << endl;
        // cout << mid << " " << j << endl;
        if (j * j + mid * mid == c)
        {
            return true;
        }
        else if (j * j + mid * mid > c)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    cout << (judgeSquareSum(n) ? "true" : "false") << endl;
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