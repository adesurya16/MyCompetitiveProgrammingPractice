#include <bits/stdc++.h>
using namespace std;
int cal1(int num)
{
    string str = to_string(num);
    int n = str.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
            count++;
    }
    return count;
}
void solve(int cases = 1)
{
    // solve the problem here
    int num;
    cin >> num;
    int n = 1000000;
    int max = 9;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += cal1(i);
        if (i == max)
        {
            cout << max << " : " << sum << endl;
            max = max * 10 + 9;
        }

        if (i == num)
            cout << num << " : " << sum << endl;
    }
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