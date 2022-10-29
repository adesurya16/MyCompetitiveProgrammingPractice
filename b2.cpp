#include <bits/stdc++.h>
using namespace std;
// link problem https://pastebin.com/PaGYdupf
// another solution https://www.geeksforgeeks.org/maximize-profit-possible-by-selling-m-products-such-that-profit-of-a-product-is-the-number-of-products-left-of-that-supplier/
// solution above TLE

long long calculateSeries(int l, int r)
{
    // l >= r
    // l + (l - 1) + l - 2 + ... + (r - 1)

    // formula below
    long long dif = l - r;
    return (long long)(dif * (dif + 1) / 2) + (long long)(dif * (long long)r);
}

long long maximumProfit(vector<int> &inventory, long long order)
{
    // O(n + nlogn) --> O(nlogn) time complexity, O(1) space somplexity
    int n = inventory.size();
    long long maxProfit = 0;
    sort(inventory.begin(), inventory.end(), greater<int>());
    inventory.push_back(0);
    int pointerRight = 0;
    while (order > 0)
    {
        int leftValue = inventory[pointerRight];
        int rightValue = inventory[pointerRight + 1];
        // long long val = calculateSeries(leftValue, rightValue);
        int size = pointerRight + 1;
        // val = val * size;
        if (order >= (size * (leftValue - rightValue)))
        {
            order -= (size * (leftValue - rightValue));
            long long val = calculateSeries(leftValue, rightValue) * size;
            maxProfit += val;
        }
        else
        {
            int divide = order / size;
            long long val1 = calculateSeries(leftValue, leftValue - divide) * size;
            // cout << "val1 : " << val1 << endl;
            int reminder = order % size;
            long long val2 = (leftValue - divide) * reminder;
            // cout << "val2 : " << val1 << endl;
            maxProfit += (val1 + val2);
            order = 0;
        }
        // cout << "order : " << order << endl;
        // cout << "maxProfit : " << maxProfit << endl;
        pointerRight++;
    }
    return maxProfit;
}

void solve(int cases = 1)
{
    // solve the problem here

    // 3 5
    // 6
    // 5 + 4 + 3 + 3 + 2 + 2 = 19

    // 10 5 3 2
    // 20
    // (10 + 9 + 8 + 7 + 6) + 2 * (5 + 4) + 3 * (3) + 4 * (2 + 1) = 40 + 18 + 9 + 12 = 79

    // 10 5 3 2
    // 6
    // (10 + 9 + 8 + 7 + 6) + 5 = 45

    int n;
    cin >> n;
    vector<int> l;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        l.push_back(num);
    }
    long long order;
    cin >> order;
    cout << maximumProfit(l, order) << endl;
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