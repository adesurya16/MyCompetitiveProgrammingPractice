#include <bits/stdc++.h>
using namespace std;

// int binominalCoefficient(int n, int k)
// {
//     int res = 1;
//     for (int i = 0; i < k; i++)
//     {
//         res *= (n - i);
//         res /= (i + 1);
//     }
//     return res;
// }

bool isValidParenthess(string str)
{
    int left = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            left++;
        }
        else
        {
            if (left > 0)
            {
                left--;
            }
            else
                return false;
        }
    }
    return (left == 0);
}

void backtracking(vector<string> &res, int left, int right, const string &str)
{
    if (left == 0 && right == 0)
    {
        if (isValidParenthess(str))
            res.push_back(str);
        return;
    }
    if (left > 0)
    {
        backtracking(res, left - 1, right, str + '(');
    }
    if (right > 0)
    {
        backtracking(res, left, right - 1, str + ')');
    }
}

vector<string> generateParenthesis(int n)
{
    // int size = binominalCoefficient(2 * n, n) / (n + 1);
    vector<string> res;

    backtracking(res, n, n, "");
    return res;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<string> res = generateParenthesis(n);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << endl;
    // }
    cout << res.size() << endl;
    for (string str : res)
    {
        cout << str << endl;
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