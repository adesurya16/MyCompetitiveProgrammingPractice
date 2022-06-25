#include <bits/stdc++.h>
using namespace std;
// flood fill algorithm
int floodFill(vector<vector<int>> &arr, int row, int col, int i, int j, int number)
{
    if (i >= 0 && i < row && j >= 0 && j < col && arr[i][j] == number)
    {
        arr[i][j] = 0;
        int right = floodFill(arr, row, col, i + 1, j, number);
        int left = floodFill(arr, row, col, i - 1, j, number);
        int bottom = floodFill(arr, row, col, i, j + 1, number);
        int top = floodFill(arr, row, col, i, j - 1, number);
        return 1 + right + left + bottom + top;
    }
    else
        return 0;
}

void solve(int cases = 1)
{
    // solve the problem here
    int col, row;
    cin >> row >> col;
    vector<vector<int>> arr = vector<vector<int>>(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                int area = floodFill(arr, row, col, i, j, arr[i][j]);
                ans = max(ans, area);
            }
        }
    }
    cout << ans * (ans - 1) << endl;
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