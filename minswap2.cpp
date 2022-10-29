#include <bits/stdc++.h>
using namespace std;

// segment tree

int findMaximumIndexSegmentTree(int n)
{
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

pair<int, int> query(vector<pair<int, int>> &st, int l, int r, int i, int ql, int qr)
{
    if (ql > r || qr < l)
    {
        return {INT_MAX, -1};
    }
    else if (ql <= l && qr >= r)
    {
        return st[i];
    }
    else
    {
        int m = l + (r - l) / 2;
        pair<int, int> pl = query(st, l, m, i * 2 + 1, ql, qr);
        pair<int, int> pr = query(st, m + 1, r, i * 2 + 2, ql, qr);
        if (pl.first < pr.first)
        {
            return pl;
        }
        else
            return pr;
    }
}

void update(vector<pair<int, int>> &st, int l, int r, int i, int val, int indexVal)
{
    if (l == r)
    {
        st[i] = {val, l};
    }
    else
    {
        int m = l + (r - l) / 2;
        if (indexVal <= m)
        {
            update(st, l, m, i * 2 + 1, val, indexVal);
        }
        else
        {
            update(st, m + 1, r, i * 2 + 2, val, indexVal);
        }
        if (st[i * 2 + 1].first < st[i * 2 + 2].first)
        {
            st[i] = st[i * 2 + 1];
        }
        else
        {
            st[i] = st[i * 2 + 2];
        }
    }
}

void build(vector<pair<int, int>> &st, vector<int> &arr, int l, int r, int i)
{
    if (l == r)
    {
        // cout << "leaf" << endl;
        // cout << arr[l] << endl;
        // cout << l << endl;
        st[i] = {arr[l], l};
    }
    else
    {
        int m = l + (r - l) / 2;
        build(st, arr, l, m, 2 * i + 1);
        build(st, arr, m + 1, r, 2 * i + 2);
        if (st[2 * i + 1].first < st[2 * i + 2].first)
        {
            st[i] = st[2 * i + 1];
        }
        else
        {
            st[i] = st[2 * i + 2];
        }
    }
}

void printArr2(vector<pair<int, int>> &st)
{
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        cout << st[i].first << " " << st[i].second << endl;
    }
}

int minimumSwaps2(vector<int> arr)
{
    // ascending order minimum swap

    // try to solve using segment tree

    // build the tree

    // for each index [0..size(arr) - 1]

    // query min(index,size - 1) in log n time

    // return index and min value, update the value in log n time
    int n = arr.size();
    int memReq = findMaximumIndexSegmentTree(n);
    // cout << memReq << endl;
    vector<pair<int, int>> segmentTree(memReq * 2 + 1, {INT_MAX, -1});
    // save <value, index>

    // build tree
    build(segmentTree, arr, 0, n - 1, 0);
    // printArr2(segmentTree);

    int swaps = 0;
    for (int i = 0; i <= (n - 2); i++)
    {
        int left = i + 1;
        int right = n - 1;
        pair<int, int> p = query(segmentTree, 0, n - 1, 0, left, right);
        if (p.first < arr[i])
        {
            swap(arr[i], arr[p.second]);
            int val1 = arr[i];
            int idx1 = i;
            int val2 = arr[p.second];
            int idx2 = p.second;
            swaps++;
            update(segmentTree, 0, n - 1, 0, val1, idx1);
            update(segmentTree, 0, n - 1, 0, val2, idx2);
        }
    }
    return swaps;
}

int minimumSwaps(vector<int> arr)
{
    int n = arr.size();
    int swaps = 0;
    int i = 0;
    while (i < n)
    {
        if (arr[i] != i + 1)
        {
            swap(arr[i], arr[arr[i] - 1]);
            swaps++;
        }
        else
        {
            i++;
        }
    }
    return swaps;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    // n can be max 10 ^ 5
    // expected time complexity O(n log n)
    // expected space complexity O(n)
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << arr[0] << endl;
    cout << minimumSwaps(arr) << endl;
    // cout << minimumSwaps2(arr) << endl;
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