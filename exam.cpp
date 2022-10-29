#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int x;
    cin >> x;
    if (x == 1)
    {
        cout << "Hello World" << endl;
    }
    else
    {
        long long a, b;
        cin >> a >> b;
        cout << a * b << endl;
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