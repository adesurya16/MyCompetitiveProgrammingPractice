#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = 0, T = 0, i = 0, u = 0, r = 0;
    for (int idx = 0; idx < n; idx++)
    {
        if (s[idx] == 'm')
            m++;
        if (s[idx] == 'T')
            T++;
        if (s[idx] == 'i')
            i++;
        if (s[idx] == 'u')
            u++;
        if (s[idx] == 'r')
            r++;
    }

    if (n == 5 && m == 1 && T == 1 && i == 1 && u == 1 && r == 1)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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