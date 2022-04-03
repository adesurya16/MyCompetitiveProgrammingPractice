#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(int r, int g, int b, int w)
{
    int countOdd = (r & 1) + (g & 1) + (b & 1) + (w & 1);

    if ((countOdd == 2) || (countOdd == 3 && (r == 0 || g == 0 || b == 0)))
        return 0;
    return 1;
}

void solve(int cases = 1)
{
    // solve the problem here
    int r, g, b, w;
    cin >> r >> g >> b >> w;
    if (isPalindrom(r, g, b, w))
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}