#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {2, 5};
    int n = 4;
    priority_queue<int> q;
    for (int i : arr)
    {
        q.push(i);
    }
    int res = 0;
    while (n--)
    {
        if (q.size() == 0)
        {
            break;
        }
        int top = q.top();
        // cout << top << endl;
        q.pop();
        res += top;
        top--;
        if (top > 0)
        {
            q.push(top);
        }
    }
    cout << res << endl;
}