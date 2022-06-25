#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    // index from 1 - n
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = n - 2;
    int end = 0;
    int sumEqual = 1;
    int EndValue = arr[n - 1];
    int operation = 0;
    while (start >= end)
    {
        if (arr[start] == EndValue)
        {
            start--;
            sumEqual++;
        }
        else
        {
            start -= sumEqual;
            operation++;
            sumEqual *= 2;
        }
    }
    cout << operation << endl;
}

int main()
{
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}