#include <bits/stdc++.h>
using namespace std;

string countSay(string s)
{
    string res = "";
    int count = 1;
    char c = s[0];
    int len = s.length();
    for (int i = 1; i < len; i++)
    {
        if (c == s[i])
        {
            count++;
        }
        else
        {
            res += to_string(count) + c;
            count = 1;
            c = s[i];
        }
    }
    res += to_string(count) + c;
    return res;
}

string countAndSay(int n)
{
    string str = "1";
    if (n == 1)
        return str;
    else
    {
        for (int i = 1; i < n; i++)
        {
            str = countSay(str);
        }
        return str;
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    cout << countAndSay(n) << endl;
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