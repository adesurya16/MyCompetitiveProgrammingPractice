#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int maxK = arr[n - 1] + m;
    int minK;
    int left = 0;
    int right = 0;

    // find minK
    while (m > 0)
    {
        right++;
        if (right == n)
        {
            int preValue = arr[right - 1];
            int width = right;
            // cout << m << " " << width << endl;
            // cout << "ceil" << endl;
            // cout << ceil((double)m / width) << endl;
            minK = preValue + ceil((double)m / width);
            m = 0;
        }
        else
        {
            int preValue = arr[right - 1];
            int curValueExpected = arr[right];
            int width = right;
            int reachValue = (curValueExpected - preValue) * width;
            // cout << "reach" << endl;
            // cout << reachValue << endl;
            if (reachValue <= m)
            {
                m -= reachValue;
                if (m == 0)
                {
                    minK = curValueExpected;
                    minK = max(minK, arr[n - 1]);
                }
            }
            else
            {
                minK = preValue + ceil((double)m / width);
                minK = max(minK, arr[n - 1]);
                m = 0;
            }
        }
    }
    cout << minK << " " << maxK << endl;
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