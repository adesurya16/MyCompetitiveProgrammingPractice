#include <bits/stdc++.h>
using namespace std;
vector<int> numbers;
int binarySearch1(int l, int r, int x)
{
    // find first data that is greater than x
    while (l <= r)
    {
    }
    return l;
}

int binarySearch2(int l, int r, int x)
{
    // find last data that is less than or equal x
    while (l <= r)
    {
    }
    return r;
}
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int left = int binarySearch1(0, n - 1, x);
        int right = int binarySearch2(0, n - 1, y);
        if (left <= right)
        {
            cout << right - left + 1 << endl;
        }
        else
            cout << 0 << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        // ascending numbers input
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}