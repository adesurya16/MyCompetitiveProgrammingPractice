// https://dunjudge.me/analysis/problems/115/
#include <bits/stdc++.h>
using namespace std;
#define fastIO() \
    ;            \
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

// void print(vector<int> arr, int pStart)
// {
//     int m = arr.size();
//     for (int i = 0; i < m; i++)
//     {
//         cout << arr[(pStart + i) % m] << " ";
//     }
//     cout << endl;
// }

void solve(int cases = 1)
{
    // solve the problem here
    int m, k;
    cin >> m >> k;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        arr[i] = i;
    }
    string s;
    cin >> s;

    // cout << m << endl;
    // cout << k << endl;
    // cout << s << endl;
    int i = 0;
    int pStart = 0;
    while (s[i] != '.')
    {
        // cout << s[i] << " : ";
        if (s[i] == 'B')
        {
            swap(arr[pStart], arr[(pStart + 1) % m]);
        }
        pStart = (pStart + 1) % m;
        // print(arr, pStart);
        i++;
    }
    int left, right;
    int mid = (pStart + k) % m;
    if (mid - 1 < 0)
    {
        left = mid + 6;
    }
    else
        left = mid - 1;
    right = (mid + 1) % m;
    cout << arr[left] << " " << arr[mid] << " " << arr[right] << endl;
    // cout << arr[(pStart + k - 1) % m] << " " << arr[(pStart + k) % m] << " " << arr[(pStart + k + 1) % m] << endl;
}

int main()
{
    fastIO();
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}