#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    // stack
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
            // cout << "currentIdx : " << currentIdx << ", "
            //      << "size : " << size << endl;
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
        // cout << "currentIdx : " << idx << ", "
        //      << "size : " << size << endl;

        largest = max(largest, size);
        idx = sIdx.top();
        sIdx.pop();
    }
    int size = n * heights[idx];
    // cout << "currentIdx : " << idx << ", "
    //      << "size : " << size << endl;
    largest = max(largest, size);
    return largest;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << largestRectangleArea(arr) << endl;
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