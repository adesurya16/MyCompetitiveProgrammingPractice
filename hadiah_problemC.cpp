#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binaryPowerMod(ll a, ll b, ll m)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve(int cases = 1)
{
    // solve the problem here
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    ll res = a;
    for (ll i = 0; i < c; i++)
    {
        res = binaryPowerMod(res, b, n);
    }
    cout << res + 1 << endl;
}

int main()
{
    // fast IO
    ios_base::sync_with_stdio(false);
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}