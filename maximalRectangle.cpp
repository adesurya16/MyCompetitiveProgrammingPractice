#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int largest = INT_MIN;
    int n = heights.size();
    stack<int> sIdx;
    sIdx.push(0);
    for (int i = 1; i < n; i++)
    {
        int num = heights[i];
        int idx = i;
        while (!sIdx.empty() && heights[sIdx.top()] > num)
        {
            int currentIdx = sIdx.top();
            sIdx.pop();
            int width;
            if (sIdx.empty())
            {
                width = idx;
            }
            else
            {
                int prevIdx = sIdx.top();
                width = idx - (prevIdx + 1);
            }
            int size = heights[currentIdx] * width; // ngintip 1 langkah dibelakangnya
            largest = max(largest, size);
        }
        sIdx.push(idx);
    }
    // stack increasing order exist
    int idx = sIdx.top();
    sIdx.pop();
    while (!sIdx.empty())
    {
        int prevIdx = sIdx.top();

        int width = n - (prevIdx + 1);
        int size = width * heights[idx];
        largest = max(largest, size);
        idx = sIdx.top();
        sIdx.pop();
    }
    int size = n * heights[idx];
    largest = max(largest, size);
    return largest;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int x = matrix.size();
    int y = matrix[0].size();
    vector<int> arr(y, 0);
    int maximal = INT_MIN;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (matrix[i][j] == '0')
            {
                arr[j] = 0;
            }
            else
                arr[j]++;
        }
        int largest = largestRectangleArea(arr);
        maximal = max(maximal, largest);
    }
    return maximal;
}

void solve(int cases = 1)
{
    // solve the problem here
    int x, y;
    cin >> x >> y;
    vector<vector<char>> matrix = vector(x, vector<char>(y));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << maximalRectangle(matrix) << endl;
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