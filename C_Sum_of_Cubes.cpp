#include <bits/stdc++.h>
using namespace std;
map<long long, int> maps;
void solve(int cases = 1)
{
    // solve the problem here
    long long number;
    cin >> number;
    int upperBound = 10000;
    bool isCubes = 0;
    for (long long i = 1; i < upperBound; i++)
    {
        long long res = number - (i * i * i);
        if (maps.find(res) != maps.end())
        {
            isCubes = 1;
        }
    }
    if (isCubes)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}

int main()
{
    int cases = 1; // 1 or more cases
    cin >> cases;
    int upperBound = 10000;
    for (long long i = 1; i < upperBound; i++)
    {
        maps[i * i * i]++;
    }
    while (cases--)
    {
        solve();
    }
    return 0;
}