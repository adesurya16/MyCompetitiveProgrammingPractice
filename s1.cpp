#include <bits/stdc++.h>
using namespace std;
pair<int, int> calculateFrek(string s)
{
    // return black and white
    int b = 0;
    int w = 0;
    for (char &c : s)
    {
        if (c == 'B')
            b++;
        else
            w++;
    }
    return {b, w};
}

string flipLeft(string s)
{
    int n = s.size();
    char c = s[0];
    int idx = -1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == c)
        {
            idx = i;
            break;
        }
    }
    if (idx != -1)
    {
        for (int i = 1; i < idx; i++)
        {
            s[i] = c;
        }
    }

    return s;
}

string flipRight(string s)
{
    int n = s.size();
    char c = s[n - 1];
    int idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == c)
        {
            idx = i;
            break;
        }
    }
    if (idx != -1)
    {
        for (int i = n - 2; i > idx; i--)
        {
            s[i] = c;
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    int b = 1;
    int w = 1;
    string initStr = "BW";
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        int idx = i + 1;
        char c;
        if (idx % 2 == 0)
        {
            c = 'W';
        }
        else
        {
            c = 'B';
        }
        if (s[idx - 1] == 'L')
        {
            initStr = c + initStr;
            initStr = flipLeft(initStr);
        }
        else
        {
            initStr = initStr + c;
            initStr = flipRight(initStr);
        }
    }
    pair<int, int> p = calculateFrek(initStr);
    cout << p.first << " " << p.second << endl;
}