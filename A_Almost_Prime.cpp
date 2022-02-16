#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
void modifiedSieve(vector<int> &primes)
{
    for (int i = 2; i < bound + 1; i++)
    {
        if (primes[i] == 0)
        {
            // i  prime
            primes[i]++;
            for (int idx = i + i; idx < bound + 1; idx += i)
            {
                primes[idx]++;
            }
        }
    }
}

void solve(int cases = 1)
{
    // like sieve()
    vector<int> primes(bound + 1, 0);

    modifiedSieve(primes);
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (primes[i] == 2)
            count++;
    }
    cout << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int cases = 1;
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}