#include <bits/stdc++.h>
using namespace std;

bool makeAP(int num[])
{
    // case 1
    // barisan ke 1
    int expectNum1 = num[1] - (num[2] - num[1]);
    if ((expectNum1 > 0) && (num[0] > 0) && (expectNum1 % num[0] == 0))
    {
        return true;
    }

    // case 2
    // barisan ke 2
    int diff = num[2] - num[0];
    if (diff % 2 == 0)
    {
        diff = diff / 2;
        int expectNum2 = num[0] + diff;
        if ((expectNum2 > 0) && (num[1] > 0) && (expectNum2 % num[1] == 0))
        {
            return true;
        }
    }

    // case 3
    // barisan ke 3
    int expectNum3 = num[1] + (num[1] - num[0]);
    if ((expectNum3 > 0) && (num[2] > 0) && (expectNum3 % num[2] == 0))
    {
        return true;
    }

    return false;
}

void solve()
{
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    if (makeAP(num))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}