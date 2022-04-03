#include <bits/stdc++.h>
using namespace std;
// void print(vector<vector<bool>> arr, int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << arr[i][j];
//         }
//         cout << endl;
//     }
//     cout << endl;
// }
void solve(int cases = 1)
{
    // solve the problem here
    int n, m;
    int xStart, yStart;
    cin >> n >> m >> xStart >> yStart;
    xStart--;
    yStart--;
    vector<vector<bool>> arr(n, vector<bool>(m, 0));

    // fill the same row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[xStart][yStart] = 1;
            cout << xStart + 1 << " " << yStart + 1 << endl;
            // print(arr, n, m);
            if (j < m - 1)
            {
                yStart = (yStart + 1) % m;
            }
        }
        xStart = (xStart + 1) % n;
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