#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int left1 = 0;
    int right0 = 0;
    vector<int> dp(n);
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            left1++;
        }
        else
        {
            dp[i] = left1;
            sum += left1;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            right0++;
        }
        else
        {
            dp[i] = right0;
        }
    }
    // cout << "sum : " << sum << endl;
    // for(int i = 0; i < n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    int leftP = 0;
    int rightP = n - 1;
    while (sum > 0 && k > 0 && leftP < rightP)
    {
        if (s[rightP] == '1')
        {
            rightP--;
            left1--;
        }
        else if (s[leftP] == '0')
        {
            leftP++;
            right0--;
        }
        else
        {
            if (left1 < right0)
            {
                sum -= dp[leftP];
                k--;
                left1--;
                leftP++;
            }
            else
            {
                sum -= dp[rightP];
                k--;
                right0--;
                rightP--;
            }
        }
    }
    cout << sum << endl;
    return 0;
}