#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    while (n--)
    {
        int num;
        cin >> num;
        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
    }
    cout << maxNum - minNum << endl;
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