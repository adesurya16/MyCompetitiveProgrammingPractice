#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    char leftC = 'B';
    int sizeB = 1;
    char rightC = 'W';
    int sizeW = 1;
    for (int i = 0; i < n; i++)
    {
        char c;
        if (i % 2 == 0)
        {
            c = 'B';
        }
        else
            c = 'W';

        if (s[i] == 'L')
        {

            if (c == 'B')
            {
                if ((leftC == 'B') || (leftC == rightC))
                {
                    sizeB++;
                }
                else
                {
                    sizeB = sizeB + sizeW + 1;
                    sizeW = 0;
                }
            }
            else
            {
                if ((leftC == 'W') || (leftC == rightC))
                {
                    sizeW++;
                }
                else
                {
                    sizeW = sizeW + sizeB + 1;
                    sizeB = 0;
                }
            }
            leftC = c;
        }
        else
        {
            if (c == 'B')
            {
                if ((rightC == 'B') || (leftC == rightC))
                {
                    sizeB++;
                }
                else
                {
                    sizeB = sizeB + sizeW + 1;
                    sizeW = 0;
                }
            }
            else
            {
                if ((rightC == 'W') || (leftC == rightC))
                {
                    sizeW++;
                }
                else
                {
                    sizeW = sizeW + sizeB + 1;
                    sizeB = 0;
                }
            }
            rightC = c;
        }
    }
    cout << sizeB << " " << sizeW << endl;
    return 0;
}