#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    double x1, y1, x2, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    // cout << d << " " << r1 + r2 << endl;
    if (d > r1 + r2)
    {
        cout << "tidak bersentuhan" << endl;
    }
    else
    {
        if (d < r1 && d + r2 < r1)
        {
            cout << "tidak bersentuhan" << endl;
        }
        else if (d < r2 && d + r1 < r2)
        {
            cout << "tidak bersentuhan" << endl;
        }
        else
            cout << "bersentuhan" << endl;
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