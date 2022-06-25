#include <bits/stdc++.h>
using namespace std;
// string printBinary(int num)
// {
//     string res = "";
//     while (num > 0)
//     {
//         res = to_string(num % 2) + res;
//         num /= 2;
//     }
//     return res;
// }

// int countXORPairs(int num)
// {
//     int count = 0;
//     for (int i = 1; i <= num - 1; i++)
//     {
//         for (int j = i + 1; j <= num; j++)
//         {
//             if (i ^ j == num)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int findleft(int num)
{
    int count = 0;
    while (num > 1)
    {
        num >>= 1;
        count++;
    }
    return count;
}

void solve(int cases = 1)
{
    // solve the problem here

    // find the pattern first

    // need to print the representation of binary from a number

    // need print xor pairs a,b <= a^b

    // take example 1 - 20

    // for (int i = 1; i <= 20; i++)
    // {
    //     cout << i << endl;
    //     cout << printBinary(i) << endl;
    //     cout << countXORPairs(i) << endl;
    //     cout << endl;
    // }

    // the formula get the binary representation of a number excep the leftmost 1 times by 2 (2,1) (1,2) count different number of 1
    // example 1011 -> 0011, 1001 -> 0001, so on
    int num, n;
    cin >> num >> n;
    map<int, int> maps;
    while (n--)
    {
        int x;
        cin >> x;
        maps[x]++;
    }
    long long count = 0;
    // int left = 1;
    // int power2 = 2;
    for (int i = 1; i <= num; i++)
    {
        // if (i == power2 * 2)
        // {
        //     power2 *= 2;
        //     left++;
        // }
        if (maps.find(i) == maps.end())
        {
            int left = findleft(i);
            count += (2 * (i ^ ((i >> left) << left)));
        }
    }
    cout << count << endl;
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