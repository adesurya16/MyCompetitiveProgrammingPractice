#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    int r = 0, g = 0, b = 0;
    for (int i = 0; i < 6; i++)
    {
        if (s[i] == 'r')
        {
            r++;
        }
        else if (s[i] == 'R' && r == 0)
        {
            return 0;
        }
        else if (s[i] == 'g')
        {
            g++;
        }
        else if (s[i] == 'G' && g == 0)
        {
            return 0;
        }
        else if (s[i] == 'b')
        {
            b++;
        }
        else if (s[i] == 'B' && b == 0)
        {
            return 0;
        }
    }
    return 1;
}
void solve(int cases = 1)
{
    // solve the problem here
    string s;
    cin >> s;
    if (isValid(s))
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