// create function solve longest polindrome substring using manacher's algorithm
#include <bits/stdc++.h>
using namespace std;
string preprocessing(string s)
{
    string res = "";
    int size = s.length();
    for (int i = 0; i < size; i++)
    {
        res = res + "#" + s[i];
    }
    res = res + "#";
    return res;
}

int manachersLPS(string s)
{
    int size = s.length();
    vector<int> lps(size, 0);
    int center = 0;
    int right = 0;
    int maxPol = 0;
    // int centerMaxPol = 0;
    for (int i = 0; i < size; i++)
    {
        int mirror = (2 * center) - i;

        if (i < right)
        {
            lps[i] = min(right - i, lps[mirror]);
        }

        // expand
        int pRight = i + (1 + lps[i]);
        int pLeft = i - (1 + lps[i]);

        while (pRight < size && pLeft >= 0 && s[pRight] == s[pLeft])
        {
            lps[i]++;
            pRight++;
            pLeft--;
        }

        if (i + lps[i] > right)
        {
            center = i;
            right = i + lps[i];

            maxPol = max(lps[i], maxPol);
        }
    }
    return maxPol;
}

void solve(int cases = 1)
{
    // solve the problem here
    string s;
    cin >> s;
    s = preprocessing(s);
    cout << manachersLPS(s) << endl;
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