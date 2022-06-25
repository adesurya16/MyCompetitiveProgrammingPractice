// dense array problem

#include <bits/stdc++.h>
using namespace std;
int insertNumbers(int left, int right)
{
    // left >= right
    // cout << left << " " << right << endl;

    int count = 0;
    while (left > (right * 2))
    {
        // cout << left << " ";
        left = ceil((double)left / 2);
        // cout << left << endl;
        count++;
    }
    return count;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    int prev = 0;
    int insertNumber = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (prev == 0)
        {
            prev = x;
        }
        else
        {
            insertNumber += insertNumbers(max(prev, x), min(prev, x));
            prev = x;
        }
    }
    cout << insertNumber << endl;
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