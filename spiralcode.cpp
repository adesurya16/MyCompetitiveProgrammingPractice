// https://leetcode.com/problems/spiral-matrix/
#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int dir = 0;
    int sizeX = matrix.size();
    int sizeY = matrix[0].size();
    // cout << sizeX << " " << sizeY << endl;
    int minRow = 0, maxRow = sizeX - 1, minCol = 0, maxCol = sizeY - 1;
    vector<int> res;
    while (minRow <= maxRow && minCol <= maxCol)
    {
        if (dir % 4 == 0)
        {
            for (int i = minCol; i <= maxCol; i++)
            {
                // cout << "i, j = matrix" << endl;
                // cout << minRow << " " << i << endl;
                // cout << matrix[minRow][i] << endl;
                res.push_back(matrix[minRow][i]);
            }
            minRow++;
        }
        else if (dir % 4 == 1)
        {
            for (int i = minRow; i <= maxRow; i++)
            {
                res.push_back(matrix[i][maxCol]);
            }
            maxCol--;
        }
        else if (dir % 4 == 2)
        {
            for (int i = maxCol; i >= minCol; i--)
            {
                res.push_back(matrix[maxRow][i]);
            }
            maxRow--;
        }
        else
        {
            for (int i = maxRow; i >= minRow; i--)
            {
                res.push_back(matrix[i][minCol]);
            }
            minCol++;
        }
        dir++;
    }
    // cout << dir << endl;
    return res;
}

void printArr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != arr.size() - 1)
        {
            cout << arr[i] << " ";
        }
        else
        {
            cout << arr[i];
        }
    }
    cout << endl;
}

void solve(int cases = 1)
{
    // solve the problem here
    int x, y;
    cin >> x >> y;
    vector<vector<int>> arr(x, vector<int>(y));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> res = spiralOrder(arr);
    printArr(res);
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