#include <bits/stdc++.h>
using namespace std;
int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int minRotations = INT_MAX;
    int n = tops.size();
    for (int domino = 1; domino <= 6; domino++)
    {
        int topRotations = 0;
        int bottomRotations = 0;
        for (int i = 0; i < n; i++)
        {
            if (tops[i] != domino && bottoms[i] != domino)
            {
                topRotations = INT_MAX;
                bottomRotations = INT_MAX;
                break;
            }
            if (tops[i] != domino)
            {
                topRotations++;
            }
            if (bottoms[i] != domino)
            {
                bottomRotations++;
            }
        }
        minRotations = min(minRotations, min(topRotations, bottomRotations));
    }
    if (minRotations != INT_MAX)
    {
        return minRotations;
    }
    return -1;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> tops(n);
    vector<int> bottoms(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tops[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> bottoms[i];
    }
    cout << minDominoRotations(tops, bottoms) << endl;
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