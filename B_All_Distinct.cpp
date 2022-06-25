#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        mp[num]++;
    }
    int numbers = 0;
    int deleted = 0;
    for (const auto &p : mp)
    {
        numbers++;
        if (p.second > 1)
        {
            deleted += p.second - 1;
        }
    }
    if (deleted % 2 == 0)
        cout << numbers << endl;
    else
        cout << numbers - 1 << endl;
}

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}