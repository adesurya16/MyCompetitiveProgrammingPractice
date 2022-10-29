#include <bits/stdc++.h>
using namespace std;
bool isPrime(int number)
{
    // cout << "isPrime : " << number << endl;
    if (number < 2)
        return false;
    if (number == 2)
        return true;
    for (int i = 2; (i * i) <= number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int convert(int a, int b)
{
    // max str = 10000 x 10000
    string str = to_string(a) + to_string(b);
    return stoi(str);
}

void solve(int cases = 1)
{
    // solve the problem here
    int x, y; // 10000
    cin >> x >> y;
    bool isExist = 0;

    // loop optimum 50x50
    for (int i = x; i <= y; i++)
    {
        for (int j = x; j <= y; j++)
        {
            if (isPrime(i) && isPrime(j) && isPrime(convert(i, j)))
            {
                isExist = 1;
                cout << i << " " << j << endl;
            }
        }
    }
    if (!isExist)
        cout << "TIDAK ADA" << endl;
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