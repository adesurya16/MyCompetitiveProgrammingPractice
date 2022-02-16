#include <bits/stdc++.h>
using namespace std;
// bool comp(int a, int b)
// {
//     return (a < b);
// }
int maxNumberOfBalloons(string text)
{
    // b == 0
    // a == 1
    // l == 2 (2)
    // o == 3 (2)
    // n == 4
    int frek[5] = {0};
    for (char c : text)
    {
        if (c == 'b')
            frek[0]++;
        if (c == 'a')
            frek[1]++;
        if (c == 'l')
            frek[2]++;
        if (c == 'o')
            frek[3]++;
        if (c == 'n')
            frek[4]++;
    }
    int minFrek = min(min(frek[0], frek[1]), min(min(frek[2] / 2, frek[3] / 2), frek[4]));
    return minFrek;
}

void solve(int cases = 0)
{
    string s;
    cin >> s;
    cout << maxNumberOfBalloons(s) << endl;
}

int main()
{
    int n = 1;
    while (n--)
    {
        solve();
    }
    return 0;
}