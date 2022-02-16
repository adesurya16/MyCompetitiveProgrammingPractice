#include <bits/stdc++.h>
using namespace std;
string sol(string s)
{
    int cur = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cur++;
        }
        else
        {
            cur = 1;
        }
        if (cur == 7)
            return "YES";
    }

    return "NO";
}
void solve()
{
    string s;
    cin >> s;
    cout << sol(s) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int n = 1;
    while (n--)
    {
        solve();
    }
    return 0;
}