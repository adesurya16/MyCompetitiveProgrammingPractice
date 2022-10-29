#include <bits/stdc++.h>
using namespace std;
#define fastIO() \
    ;            \
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
void solve(int cases = 1)
{
    // solve the problem here
    int x, y;
    cin >> x >> y;
    if ((x + y) & 1)
    {
        cout << "-1 -1" << endl;
    }
    else
    {
        cout << (x + y) / 2 << " " << (x + y) / 2 << endl;
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