#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
        return 0;
    int longest = INT_MIN;
    int size = s.size();
    int left = 0;
    int right;
    set<char> setChar;
    // 2 pointer + set
    for (right = 0; right < size; right++)
    {
        if (setChar.find(s[right]) == setChar.end())
        {
            setChar.insert(s[right]);
            longest = max(right - left + 1, longest);
        }
        else
        {
            while (s[left] != s[right])
            {
                setChar.erase(s[left]);
                left++;
            }
            left++;
        }
    }
    return longest;
}

void solve(int cases = 1)
{
    // solve the problem here
    // longest subtring without repeating character problem
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
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