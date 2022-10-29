#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int a, b, c;
    cin >> a >> b >> c;
    if (c - b == b - a)
    {
        cout << c + (c - b) << endl;
    }
    else
    {
        cout << c * (c / b) << endl;
    }
}

int main()
{
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}