#include <bits/stdc++.h>
using namespace std;
void computeLPS(string str, vector<int> &lps)
{
    int len = str.size();
    int lenLPS = 0;
    lps[0] = 0;
    int i = 1;
    while (i < len)
    {
        if (str[i] == str[lenLPS])
        {
            lenLPS++;
            lps[i] = lenLPS;
            i++;
        }
        else
        {
            if (lenLPS != 0)
            {
                lenLPS = lps[lenLPS - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmp(string text, string str)
{
    // find lps of str (lps means longest prefix suffix)
    int lenStr = str.size();
    int lenTxt = text.size();
    vector<int> lps(lenStr, 0);
    computeLPS(str, lps);

    // iterate and optimize using kmp algorithm

    int i = 0; // index for text
    int j = 0; // index for str/pattern
    while ((lenTxt - i) >= (lenStr - j))
    {
        if (text[i] == str[j])
        {
            i++;
            j++;
        }
        else if (i < lenTxt && text[i] != str[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }

        if (j == lenStr)
        {
            return i - j;
            // j = lps[j - 1]; next pattern if exist and need
        }
        //
    }
    return -1;
}

int strStr(string haystack, string needle)
{
    return kmp(haystack, needle);
}
void solve(int cases = 1)
{
    // solve the problem here
    string pattern, text;
    cin >> text;
    cin >> pattern;
    cout << strStr(text, pattern) << endl;
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