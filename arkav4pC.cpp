// https://tlx.toki.id/problems/arkavidia-4-pc-penyisihan/C
// predict using segment tree (range AND Queryt)
#include <bits/stdc++.h>
using namespace std;

const int signedAnd = -1;

void build()
{
}

int query()
{
}

void solve(int cases = 1)
{
    // solve the problem here
    int n, q;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    // create segment tree from numbers

    cin >> q;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        // precess range query
    }
}

int main()
{
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}