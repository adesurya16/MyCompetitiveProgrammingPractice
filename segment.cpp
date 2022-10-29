/*
    Example of segment tree problem
    range minimum query (RMQ) problem
*/

#include <bits/stdc++.h>
using namespace std;

void buildSegment(vector<int> &segmentTree, vector<int> &arr, int left, int right, int index)
{
    if (left == right)
    {
        segmentTree[index] = arr[left];
    }
    else
    {
        int mid = left + (right - left) / 2;
        buildSegment(segmentTree, arr, left, mid, 2 * index + 1);
        buildSegment(segmentTree, arr, mid + 1, right, 2 * index + 2);
        segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]); // min of left and right child, rely on problem can use sum/max/min etc
    }
}

int querySegment(vector<int> &segmentTree, int left, int right, int qleft, int qright, int index)
{
    if (qleft > right || qright < left)
    {
        return INT_MAX;
    }
    else if (qleft <= left && qright >= right)
    {
        return segmentTree[index];
    }
    else
    {
        int mid = left + (right - left) / 2;
        int leftChild = querySegment(segmentTree, left, mid, qleft, qright, 2 * index + 1);
        int rightChild = querySegment(segmentTree, mid + 1, right, qleft, qright, 2 * index + 2);
        return min(leftChild, rightChild);
    }
}

void updateSegment(vector<int> &segmentTree, int left, int right, int index, int indexUpdate, int valueUpdate)
{
    if (left == right)
    {
        segmentTree[index] = valueUpdate;
    }
    else
    {
        int mid = left + (right - left) / 2;
        if (indexUpdate <= mid)
        {
            updateSegment(segmentTree, left, mid, index * 2 + 1, indexUpdate, valueUpdate);
        }
        else
        {
            updateSegment(segmentTree, mid + 1, right, index * 2 + 2, indexUpdate, valueUpdate);
        }
        segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]); // min of left and right child, rely on problem can use sum/max/min etc
    }
}

int findMaximumIndexSegmentTree(int n)
{
    // closest power of 2
    // 4 -> 4
    // 5 -> 8
    // 6 -> 8

    // if n power of 2, return n
    if (n && !(n & (n - 1)))
    {
        return n;
    }
    int indexMax = 1;
    while (n > 0)
    {
        n >>= 1;
        indexMax <<= 1;
    }
    return indexMax;
}

void printSegment(vector<int> &segmentTree)
{
    for (int i = 0; i < segmentTree.size(); i++)
    {
        cout << segmentTree[i] << " ";
    }
    cout << endl;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> arr(n);
    int indexMax = findMaximumIndexSegmentTree(n);
    // cout << indexMax << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int initValue = INT_MIN;
    vector<int> arrSegment(2 * indexMax, initValue);
    buildSegment(arrSegment, arr, 0, n - 1, 0);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int left, right;
        cin >> left >> right;
        cout << querySegment(arrSegment, 0, n - 1, left, right, 0) << endl;
    }
    // printSegment(arrSegment);
    // updateSegment(arrSegment, 0, n - 1, 0, 0, -1);
    // printSegment(arrSegment);
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