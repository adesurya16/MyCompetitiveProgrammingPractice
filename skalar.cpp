#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (nums1[i] * nums2[i]);
    }
    cout << sum << endl;
    return 0;
}