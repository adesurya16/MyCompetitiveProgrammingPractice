// pairs with give xor
// expected O(n) time and O(n) space
#include <bits/stdc++.h>
using namespace std;

int SolutionSolve(vector<int> &A, int B)
{
    // set
    set<int> f;

    // set result not need because distinct
    for (int i = 0; i < A.size(); i++)
    {
        f.insert(A[i]);
    }

    int sum = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (f.find(A[i] ^ B) != f.end())
        {
            sum++;
        }
        f.erase(A[i]);
    }
    return sum;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n; // 10^5
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int b;
    cin >> b;
    cout << SolutionSolve(arr, b) << endl;
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