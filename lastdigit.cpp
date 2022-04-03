// last digit spoj
#include <bits/stdc++.h>
using namespace std;

int powerMod(int base, int pow, int modNum)
{
    base = base % modNum;
    int res = 1;
    while (pow > 0)
    {
        if (pow & 1)
            res = (res * base) % modNum;
        base = (base * base) % modNum;
        pow >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 || a == 1)
        {
            cout << a << endl;
        }
        else
            cout << powerMod(a, b, 10) << endl;
    }
    return 0;
}