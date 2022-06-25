#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll cases = 1)
{
    // solve the problem here
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> res(n);
    stack<ll> stackIndex;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        ll num = arr[i];
        ll visible = 1;
        while (stackIndex.size() > 0 && arr[stackIndex.top()] <= num)
        {
            visible += res[stackIndex.top()];
            stackIndex.pop();
        }
        stackIndex.push(i);
        res[i] = visible;
        sum += res[i];
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << res[i] << " ";
    // }
    // cout << endl;
    cout << sum << endl;
}

int main()
{
    ll cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}