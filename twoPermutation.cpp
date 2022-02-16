#include <bits/stdc++.h>
using namespace std;
bool isPermute(vector<int> nums)
{
    for (int i = nums.size() - 1; i >= 1; i--)
    {
        if (nums[i] > 0)
        {
            while (nums[i] > 1)
            {
                int idx = i / 2;
                while (idx > 0)
                {
                    if (nums[idx] == 0)
                    {
                        nums[idx]++;
                        nums[i]--;
                        break;
                    }
                    else
                        idx = idx / 2;
                }
                if (idx == 0)
                    return false;
            }
        }
        else
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> numbers(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        while (num > n)
        {
            num = num / 2;
        }
        // cerr << num << " ";
        numbers[num]++;
    }
    // cerr << endl;

    if (isPermute(numbers))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int cases;
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}