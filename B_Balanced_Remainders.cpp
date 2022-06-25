#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    // Balanced Remainders Problem
    int n;
    cin >> n; // n | 3
    vector<int> maps(3, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        maps[x % 3]++;
    }
    int balanced = n / 3;
    // cout << maps[0] << " " << maps[1] << " " << maps[2] << endl;
    // cout << (maps[0] > balanced ? maps[0] - balanced : 0) + (maps[1] > balanced ? maps[1] - balanced : 0) + (maps[2] > balanced ? maps[2] - balanced : 0) << endl;
    int start = 0;
    int moves = 0;
    while (maps[0] != maps[1] || maps[1] != maps[2] || maps[0] != maps[2])
    {
        if (maps[start] > balanced)
        {
            maps[(start + 1) % 3] += maps[start] - balanced;
            moves += (maps[start] - balanced);
            maps[start] = balanced;
        }
        start = (start + 1) % 3;
    }
    cout << moves << endl;
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