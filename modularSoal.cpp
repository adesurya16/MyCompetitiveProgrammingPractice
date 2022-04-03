#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i = 1;
    int j = 1;
    int max = 1994;
    while (i <= max)
    {
        if (((j + 1) * (j + 1) - 1) % 3 == 0)
        {
            i++;
            cout << (j + 1) * (j + 1) - 1 << endl;
        }
        if (i > max)
        {
            cout << j << endl;
            cout << ((j + 1) * (j + 1) - 1) % 1000 << endl;
        }
        j++;
    }
}