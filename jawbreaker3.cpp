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

void printArr(vector<vector<int>> arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j > 0)
                cout << " ";
            if (arr[i][j] == 0)
            {
                cout << ".";
            }
            else
                cout << arr[i][j];
        }
        cout << endl;
    }
}

void fallDown(vector<vector<int>> &arr, int row, int col)
{
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            if (arr[i][j] != 0)
            {
                int tmp_i = i;
                while (tmp_i + 1 < arr.size() && arr[tmp_i + 1][j] == 0)
                {
                    arr[tmp_i + 1][j] = arr[tmp_i][j];
                    arr[tmp_i][j] = 0;
                    tmp_i++;
                }
            }
        }
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    int col, row;
    cin >> row >> col;
    vector<vector<int>> arr = vector<vector<int>>(row, vector<int>(col, 0));
    vector<vector<int>> ans = vector<vector<int>>(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
            ans[i][j] = arr[i][j];
        }
    }
    int maxAns = 0;
    int maxX = 0;
    int maxY = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                int area = floodFill(arr, row, col, i, j, arr[i][j]);
                if (area > maxAns)
                {
                    maxAns = area;
                    maxX = i;
                    maxY = j;
                }
            }
        }
    }
    int flood = floodFill(ans, row, col, maxX, maxY, ans[maxX][maxY]);
    fallDown(ans, row, col);
    printArr(ans, row, col);
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