// fruit into basket problem
// https://leetcode.com/problems/fruit-into-baskets/

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    // should be O(n) time and O(1) space
    int n = fruits.size();
    int maxBasket = 2;

    // sliding window
    int left = 0;
    map<int, int> arrMap;
    int maxLen = 0;
    for (int right = 0; right < n; right++)
    {
        arrMap[fruits[right]]++;
        while (arrMap.size() > maxBasket)
        {
            arrMap[fruits[left]]--;
            if (arrMap[fruits[left]] == 0)
            {
                arrMap.erase(fruits[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
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
    cout << totalFruit(arr) << endl;
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