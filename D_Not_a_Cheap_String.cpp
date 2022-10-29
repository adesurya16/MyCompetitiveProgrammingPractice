#include <bits/stdc++.h>
using namespace std;

int getNum(char a)
{
    return (int)a - (int)'a';
}

void printFrek(vector<int> abc)
{
    for (int i = 0; i < 26; i++)
    {
        cout << i << " : " << abc[i] << " , ";
    }
    cout << endl;
}

void solve(int cases = 1)
{
    // solve the problem here
    string s;
    cin >> s;
    int p;
    cin >> p;
    vector<int> abc(26, 0);
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum += (getNum(s[i]) + 1);
        abc[getNum(s[i])]++;
    }
    // cout << sum << endl;
    // printFrek(abc);
    int start = 25;
    while (sum > p && start >= 0)
    {
        if (abc[start] > 0)
        {
            sum -= (start + 1);
            abc[start]--;
        }
        else
        {
            start--;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (abc[getNum(s[i])] > 0)
        {
            cout << s[i];
            abc[getNum(s[i])]--;
        }
    }
    cout << endl;
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