#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    int firstPlace = 3, secondPlace = 2, thirdPlace = 1;
    n = n - 6;
    firstPlace += (n / 3);
    secondPlace += (n / 3);
    thirdPlace += (n / 3);
    if (n % 3 == 1)
        firstPlace++;
    else if (n % 3 == 2)
    {
        firstPlace++;
        secondPlace++;
    }
    cout << secondPlace << " " << firstPlace << " " << thirdPlace << endl;
}

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}