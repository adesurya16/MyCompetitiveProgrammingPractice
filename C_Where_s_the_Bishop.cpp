#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here
    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }
    int ansX = -1, ansY = -1;
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if (board[i][j] == '#' && board[i - 1][j - 1] == '#' && board[i - 1][j + 1] == '#' && board[i + 1][j - 1] == '#' && board[i + 1][j + 1] == '#')
            {
                ansX = i;
                ansY = j;
                cout << ansX + 1 << " " << ansY + 1 << endl;
                break;
            }
        }
        if (ansX != -1 && ansY != -1)
            break;
    }
}

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}