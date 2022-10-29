#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<int, int> leftV, rightV;
    for (int i = 0; i < n; i++)
    {
        if (leftV.find(v[i]) == leftV.end())
        {
            leftV[v[i]] = i;
        }
        rightV[v[i]] = i;
    }
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        if (leftV.find(l) != leftV.end() && rightV.find(r) != rightV.end() && leftV[l] <= rightV[r])
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
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