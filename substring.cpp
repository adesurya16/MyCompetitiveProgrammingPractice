// longest polindorm substring problem using O(N^2) time complexity & using malacher complexity
#include <bits/stdc++.h>
using namespace std;

// passed testcase
int lps1(string s)
{
    // prepare O(N^2) dp table size complexity
    // [i,j] represent how long subtring i until j from string s (s[i,j]) palindrom (if no represent 0)
    // dp[i, j] i == j always 1
    int size = s.length();
    vector<vector<int>> dp = vector(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
    {
        dp[i][i] = 1;
    }
    int maxLen = 1;
    for (int i = 1; i < size; i++) // skip first iteration because init dp i == j
    {
        for (int j = i; j < size; j++)
        {
            int idxi = j - i;
            int idxj = j;
            // cout << "(" << idxi << " , " << idxj << ") ";
            if (s[idxi] == s[idxj])
            {
                if (idxi + 1 > idxj - 1)
                {
                    dp[idxi][idxj] = 2;
                }
                else if (dp[idxi + 1][idxj - 1] > 0)
                {
                    dp[idxi][idxj] = 2 + dp[idxi + 1][idxj - 1];
                }
            }
            maxLen = max(maxLen, dp[idxi][idxj]);
        }
        // cout << endl;
    }
    // print(dp);
    return maxLen;
}

// passed testcase
int lps2(string s)
{
    // this alghorithm O(N^2) time and not need any memory complexity O(1)
    // need to start form the center *C* or first left center *Cc*
    int size = s.length();
    int maxLen = 1;
    for (int i = 0; i < size; i++)
    {
        // odd length
        int length = 1;
        int left = i - 1;
        int right = i + 1;
        while (left >= 0 && right < size && s[left] == s[right])
        {
            length += 2;
            left--;
            right++;
        }
        maxLen = max(maxLen, length);

        // even length
        length = 0;
        left = i;
        right = i + 1;
        while (left >= 0 && right < size && s[left] == s[right])
        {
            length += 2;
            left--;
            right++;
        }
        maxLen = max(maxLen, length);
    }
    return maxLen;
}

// manacher algorithm
int lps3(string s)
{
    // preprocessing #s#s#s#
    string str = "#";
    for (int i = 0; i < s.length(); i++)
    {
        str = str + s[i] + "#";
    }
    // cout << str << endl;
    int size = str.length();
    vector<int> dp = vector(size, 0);
    int center = 0, right = 0, maxLen = 0;

    for (int i = 0; i < size; i++)
    {
        int mirror = (2 * center) - i;
        if (i < right)
        {
            dp[i] = min(right - i, dp[mirror]);
        }

        // expand
        int pRight = i + (1 + dp[i]);
        int pLeft = i - (1 + dp[i]);

        while (pRight < size && pLeft >= 0 && str[pRight] == str[pLeft])
        {
            dp[i]++;
            pRight++;
            pLeft--;
        }

        if (i + dp[i] > right)
        {
            center = i;
            right = i + dp[i];

            maxLen = max(maxLen, dp[i]);
        }
    }
    return maxLen;
}

int lps1Bool(string s)
{
    int size = s.length();
    vector<vector<bool>> dp = vector(size, vector<bool>(size, 0));
    for (int i = 0; i < size; i++)
    {
        dp[i][i] = 1;
    }
    int maxLen = 1;
    for (int i = 1; i < size; i++) // skip first iteration because init dp i == j
    {
        for (int j = i; j < size; j++)
        {
            int idxi = j - i;
            int idxj = j;
            // cout << "(" << idxi << " , " << idxj << ") ";
            if (s[idxi] == s[idxj])
            {
                if (idxi + 1 > idxj - 1)
                {
                    dp[idxi][idxj] = 1;
                }
                else
                    dp[idxi][idxj] = dp[idxi + 1][idxj - 1];
            }
            else
            {
                dp[idxi][idxj] = 0;
            }

            if (dp[idxi][idxj])
            {
                maxLen = max(maxLen, idxj - idxi + 1);
            }
        }
        // cout << endl;
    }
    return maxLen;
}

void solve(int cases = 1)
{
    // solve the problem here
    string s;
    cin >> s;
    // cout << lps1(s) << endl;
    // cout << lps2(s) << endl;
    cout << lps1Bool(s) << endl;
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