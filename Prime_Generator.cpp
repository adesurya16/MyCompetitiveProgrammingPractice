#include <bits/stdc++.h>
using namespace std;
vector<int> primes;

#define fastIO() \
    ;            \
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
void sieve(int maxVal)
{
    vector<bool> isPrimes(maxVal + 1, 1);
    for (int i = 2; i <= maxVal; i++)
    {
        if (isPrimes[i])
        {
            primes.push_back(i);
            for (int j = i + i; j <= maxVal; j += i)
            {
                isPrimes[j] = 0;
            }
        }
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    int m, n;
    cin >> m >> n;

    // sieve
    // cout << primes.size() << endl;
    // for (auto &num : primes)
    // {
    //     cout << num << endl;
    // }
    for (int i = m; i <= n; i++)
    {
        bool isPrimeNumber = 1;
        for (int j = 0; j < primes.size(); j++)
        {

            if (i == primes[j])
            {
                break;
            }
            else if (i % primes[j] == 0 || i == 1)
            {
                isPrimeNumber = 0;
                break;
            }
        }
        if (isPrimeNumber)
            cout << i << endl;
    }
    if (cases > 0)
        cout << endl;
}

int main()
{
    fastIO();
    int maxValue = 1000000000;
    maxValue = (int)sqrt(maxValue);
    sieve(maxValue);

    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve(cases);
    }
    return 0;
}