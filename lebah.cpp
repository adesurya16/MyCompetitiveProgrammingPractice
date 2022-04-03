#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> s;
ll upperBound = 1e18;
void preprocess()
{
    ll prev = 1, next = 2;
    s.push_back(1);
    ll sum = prev + next;
    int idx = 0;
    while (sum < upperBound)
    {
        // cout << sum << endl;
        idx++;
        s.push_back(sum);
        int tmp = prev + next;
        prev = next;
        next = tmp;
        sum += tmp;
    }
    // cout << idx << endl;
}

bool binarySearch(vector<ll> &arr, ll target)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target == arr[mid])
            return true;
        else if (target > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

void solve(int cases = 1)
{
    // solve the problem here
    ll n;
    cin >> n;
    // if (binarySearch(s, n))
    // {
    //     cout << "yes" << endl;
    // }
    // else
    //     cout << "no" << endl;
    if (n == 1)
    {
        cout << "yes" << endl;
        return;
    }
    ll prev = 1, next = 2;
    // s.push_back(1);
    ll sum = prev + next;
    int idx = 0;
    while (sum < n)
    {
        // cout << sum << endl;
        // idx++;
        // s.push_back(sum);
        int tmp = prev + next;
        prev = next;
        next = tmp;
        sum += tmp;
    }
    cout << (sum == n ? "yes" : "no") << endl;
}

int main()
{
    // preprocess();
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}