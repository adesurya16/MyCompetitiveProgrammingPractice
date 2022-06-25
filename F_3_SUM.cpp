#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    // vector<int> arr(n);
    vector<int> remainder(10);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        remainder[x % 10]++;
    }
    // bool ans = 0;
    for (int i = 0; i < 10; i++)
    {
        if (remainder[i] > 0)
        {
            remainder[i]--;
            for (int j = 0; j < 10; j++)
            {
                if (remainder[j] > 0)
                {
                    remainder[j]--;
                    for (int k = 0; k < 10; k++)
                    {
                        if (remainder[k] > 0 && (i + j + k) % 10 == 3)
                        {
                            cout << "YES" << endl;
                            return;
                        }
                    }
                    remainder[j]++;
                }
            }
            remainder[i]++;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}