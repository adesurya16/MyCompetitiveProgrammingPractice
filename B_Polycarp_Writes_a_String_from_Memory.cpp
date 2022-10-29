#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    string s;
    cin >> s;
    int start = 0;
    int day = 0;
    while (start < s.size())
    {
        day++;
        set<char> letters;
        for (int i = start; i < s.size(); i++)
        {
            start = i;
            if (letters.find(s[i]) == letters.end())
            {
                if (letters.size() < 3)
                {
                    letters.insert(s[i]);
                }
                else
                {
                    break;
                }
            }
            if (start == s.size() - 1)
            {
                start++;
                break;
            }
        }
    }
    cout << day << endl;
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