#include <bits/stdc++.h>
using namespace std;



void solve(int cases = 1)
{
    // solve the problem here
    int n;
    // n >= 7 && n <= 10000
    cin >> n;

    cout << n - 1 << endl;

    while (n > 2)
    {
        cout << 1 << " ";
        n--;
    }
    cout << 2 << endl;
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