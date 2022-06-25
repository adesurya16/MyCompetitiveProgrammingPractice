#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    if (b > a)
        ans++;
    if (c > a)
        ans++;
    if (d > a)
        ans++;
    cout << ans << endl;
}

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}