#include <bits/stdc++.h>
using namespace std;
void swapNum(int &a, int &b)
{
    // swap integer without temporary variable
    if (a != b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

void swapNum2(int &a, int &b)
{
    // be carefull with the overflow of int
    if (a != b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    int a, b;
    cin >> a >> b;
    swapNum2(a, b);
    cout << a << " " << b << endl;
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