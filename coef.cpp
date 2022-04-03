#include <bits/stdc++.h>
using namespace std;
int binominalCoefficient(int n, int k)
{
    if (n - k < k)
        k = n - k;
    int res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
void solve(int cases = 1)
{
    // solve the problem here
    int n, k;
    cin >> n >> k;
    cout << binominalCoefficient(n, k) << endl;
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