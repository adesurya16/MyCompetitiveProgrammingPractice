#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'A']++;
    }

    // create prio q
    priority_queue<pair<char, int>> prioQ;

    return 0;
}