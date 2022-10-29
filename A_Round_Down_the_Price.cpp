#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    long long n;
    cin >> n;
    long long bound = 1;
    while (bound * 10 <= n)
    {
        bound *= 10;
    }
    cout << n - bound << endl;
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