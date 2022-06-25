// https://www.geeksforgeeks.org/find-next-greater-number-set-digits/
// if none/ not possible, return descending order/circularly order
#include <bits/stdc++.h>
using namespace std;

// next permutation algorithm
string next_perm(string s)
{
    string tmp = s;
    int n = s.size();
    for (int i = n - 2; i >= 0; i--)
    {
        // cout << s[i] << " " << s[i + 1] << endl;
        if (s[i] < s[i + 1])
        {
            int j = n - 1;
            while (s[i] >= s[j])
            {
                j--;
            }
            swap(s[i], s[j]);
            reverse(s.begin() + i + 1, s.end()); // stl
            return s;
        }
    }
    return "-1";
}

void solve(int cases = 1)
{
    // solve the problem here
    string s;
    cin >> s;
    cout << next_perm(s) << endl;
    // next_permutation(s.begin(), s.end());
    // cout << s << endl;
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