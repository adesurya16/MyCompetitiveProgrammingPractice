#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void printRes(vector<vector<int>> &res)
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            if (j == 0)
                cout << res[i][j];
            else
                cout << ", " << res[i][j];
        }
        cout << "]" << endl;
    }
}

void combination(int left, int right, int k, vector<int> tmp)
{
    if (k == 0)
    {
        res.push_back(tmp);
    }
    else
    {
        for (int i = left; i <= right - k + 1; i++)
        {
            tmp.push_back(i);
            combination(i + 1, right, k - 1, tmp);
            tmp.pop_back();
        }
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    int n, k;
    cin >> n >> k;
    vector<int> tmp;
    combination(1, n, k, tmp);
    printRes(res);
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