#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i == n - 1)
            cout << endl;
        else
            cout << " ";
    }
}
void mergeSort(vector<int> &target, vector<int> &arr1, vector<int> &arr2)
{
    int size1 = arr1.size();
    int size2 = arr2.size();
    int i = 0;
    int j = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            target.push_back(arr1[i]);
            i++;
        }
        else
        {
            target.push_back(arr2[j]);
            j++;
        }
    }
    while (i < size1)
    {
        target.push_back(arr1[i]);
        i++;
    }
    while (j < size2)
    {
        target.push_back(arr2[j]);
        j++;
    }
}

void build(vector<vector<int>> &sTree, vector<int> &arr, int idx, int left, int right)
{
    if (left == right)
    {
        sTree[idx] = {arr[left]};
    }
    else
    {
        int mid = left + (right - left) / 2;
        build(sTree, arr, 2 * idx + 1, left, mid);
        build(sTree, arr, 2 * idx + 2, mid + 1, right);
        mergeSort(sTree[idx], sTree[idx * 2 + 1], sTree[idx * 2 + 2]);
    }
}

int binarySearch(vector<int> &arr, int target)
{
    int l = 0;
    int r = arr.size() - 1;
    if (target <= arr[0])
    {
        return -1;
    }
    if (target > arr[r])
    {
        return r;
    }
    // arr[mid] < target [t, t, t, f, f]
    // cout << "binary search" << endl;
    // printArr(arr);
    // cout << target << endl;
    // cout << endl;
    int res = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] < target)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}

int query(vector<vector<int>> &sTree, int left, int right, int qLeft, int qRight, int idx, int target)
{

    if (left > qRight || right < qLeft)
    {
        return 0;
    }
    else if (left >= qLeft && right <= qRight)
    {
        int id = binarySearch(sTree[idx], target); // find last true < target
        if (id == -1)
            return 0;
        else
            return id + 1;
    }
    else
    {
        int mid = left + (right - left) / 2;
        int countLeft = query(sTree, left, mid, qLeft, qRight, idx * 2 + 1, target);
        int countRight = query(sTree, mid + 1, right, qLeft, qRight, idx * 2 + 2, target);
        return countLeft + countRight;
    }
}

// should be 2^n size of arr
void printTree(vector<vector<int>> &sTree, int sizeArr)
{
    for (int i = 0; i <= (sizeArr * 2 - 1); i++)
    {
        cout << i << " : ";
        for (int j = 0; j < sTree[i].size(); j++)
        {
            cout << sTree[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    const int maxNode = 100000 * 2;
    // {min, max}
    // vector<vector<int>> sTree(maxNode, {INT_MAX, INT_MIN});

    // segment tree each node containt ascending array

    // build combine from left and right node as a merge sort combine step

    vector<vector<int>> sTree(maxNode);

    // build
    build(sTree, nums, 0, 0, n - 1);
    // printTree(sTree, n);

    // query from 0 to n - 2 as value k
    vector<int> res;
    // cout << "query 1 : ";
    // cout << query(sTree, 0, n - 1, 1, n - 1, 0, nums[0]) << endl;
    // cout << "query" << endl;
    for (int i = 0; i <= n - 2; i++)
    {
        int target = nums[i];
        int left = i + 1;
        int right = n - 1;
        // query
        int count = query(sTree, 0, n - 1, left, right, 0, target);
        res.push_back(count);
    }
    res.push_back(0);
    return res;
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
    printArr(countSmaller(arr));
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