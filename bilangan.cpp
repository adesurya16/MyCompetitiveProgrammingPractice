#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(long long n)
{
    long long sqrtN = sqrt(n);
    return sqrtN * sqrtN == n;
}
int main()
{
    long long i = 1;
    while (i < 100000000)
    {
        if (isPerfectSquare(i * (i + 2022)))
        {
            cout << i << endl;
        }
        i++;
    }
    return 0;
}