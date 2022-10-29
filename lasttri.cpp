#include <bits/stdc++.h>
using namespace std;
#define fastIO() \
    ;            \
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
void solve(int cases = 1)
{
    // solve the problem here
    int x, y, z;
    cin >> x >> y >> z;
    if ((x == y && z - 1 == x && x > 1) || (x == z && y - 1 == x && x > 1) || (y == z && x - 1 == z && y > 1))
    {
        cout << "Ya" << endl;
    }
    else
        cout << "Tidak" << endl;
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
