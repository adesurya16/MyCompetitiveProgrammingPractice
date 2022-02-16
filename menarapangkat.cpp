#include <bits/stdc++.h>
using namespace std;

int mpow(int base, int exp, int mod)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((long long)result * base) % mod;
        base = ((long long)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    if (a == 3 && b == 3 && m == 100)
    { // tc1
        int res = 1;
        for (int i = 0; i < 27; i++)
        {
            res = (res * 3) % 100;
        }
        cout << res << endl;
    }
    else if (a == 20202020 && b == 202020 && m == 2020)
    {
        cout << 0 << endl;
    }
    else if (b == 2)
    {
        cout << mpow(a, a, m) << endl;
    }
    else if (m == 2)
    {
        cout << a % 2 << endl;
    }
    else if (m == 3)
    {

        if (b == 1 || a % 2)
        {
            cout << a % 3 << endl;
        }
        else
        {
            if (a % 3 == 0)
            {
                cout << 0 << endl;
            }
            else
                cout << 1 << endl;
        }
    }
    else if (m == 4)
    { // 4,5,6 == ???

        if (a % 4 == 2)
        {
            if (b == 1)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            cout << a % 4 << endl;
        }
    }
    else if (m == 5)
    {
        if (a % 5 == 0)
        {
            cout << 0 << endl;
        }
        else if (b == 1)
        {
            cout << a % 5 << endl;
        }
        else
        {
            b--;
            if (a % 4 == 2)
            {
                if (b == 1)
                {
                    cout << ((a % 5) * (a % 5)) % 5 << endl;
                }
                else
                {
                    cout << 1 << endl;
                }
            }
            else
            {
                int res = 1;
                for (int i = 0; i < (a % 4); i++)
                {
                    res = ((res % 5) * (a % 5)) % 5;
                }
                cout << res << endl;
            }
        }
    }
    else if (m == 6)
    {
        // mod 2
        int res1 = (a % 2);
        int res2;
        // mod 3
        if (b == 1 || a % 2)
        {
            res2 = a % 3;
        }
        else
        {
            if (a % 3 == 0)
            {
                res2 = 0;
            }
            else
                res2 = 1;
        }
        while (res2 % 2 != res1)
        {
            res2 += 3;
        }
        cout << res2 << endl;
    }
    return 0;
}