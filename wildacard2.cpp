#include <bits/stdc++.h>
using namespace std;

int idxWildCard(string s)
{
    int idx = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            idx = i;
            break;
        }
    }
    return idx;
}

bool isRightWildCard(int len, string wildcard, string s)
{
    if (len > 0)
    {
        int StartWildCard = wildcard.size() - 1;
        int StartS = s.size() - 1;
        while (len--)
        {
            if (StartS < 0)
                return false;
            if (wildcard[StartWildCard] != s[StartS])
                return false;
            StartWildCard--;
            StartS--;
        }
        return true;
    }
    else
        return true;
}

bool isLeftWildCard(int len, string wildcard, string s)
{
    if (len > 0)
    {
        int StartWildCard = 0;
        int StartS = 0;
        while (len--)
        {
            if (StartS >= s.size())
                return false;
            if (wildcard[StartWildCard] != s[StartS])
                return false;
            StartWildCard++;
            StartS++;
        }
        return true;
    }
    else
        return true;
}

void solve(int cases = 1)
{
    // solve the problem here
    string wildcard;
    cin >> wildcard;
    int len = wildcard.size();
    // find *
    int idx = idxWildCard(wildcard);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        // cout << isLeftWildCard(idx, wildcard, s) << " " << isRightWildCard(len - idx - 1, wildcard, s) << endl;
        if (isLeftWildCard(idx, wildcard, s) && isRightWildCard(len - idx - 1, wildcard, s))
        {
            cout << s << endl;
        }
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