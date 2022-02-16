#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    vector<bool> frekNum(26, false);
    int pairs = 0;
    int currentLen = 0;
    int len, pol;
    cin >> len >> pol;
    string s;
    cin >> s;
    for (auto &c : s)
    {
        if (frekNum[(int)c - (int)'a'])
        {
            currentLen--;
            pairs++;
            frekNum[(int)c - (int)'a'] = false;
        }
        else
        {
            currentLen++;
            frekNum[(int)c - (int)'a'] = true;
        }
    }
    int ans = (pairs / pol) * 2;
    currentLen += (pairs % pol) * 2;
    if (currentLen >= pol)
    {
        ans++;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int cases;
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}