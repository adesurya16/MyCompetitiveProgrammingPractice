#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1)
{
    // solve the problem here

    // set<char> s = {'C', 'C', 'D', 'A'};
    // s.insert('B');
    // // s.erase('C');
    // if (s.find('C') == s.end())
    // {
    //     cout << "couldn't find C" << endl;
    // }
    // else
    // {
    //     cout << "found C!" << endl;
    // }
    // for (auto itr = s.begin(); itr != s.end(); ++itr)
    // {
    //     cout << *itr << endl;
    // }

    set<pair<int, int>> sPair;
    sPair.insert(make_pair(1, 2));
    sPair.insert(make_pair(2, 2));
    sPair.insert(make_pair(2, 1));
    // sPair.erase(make_pair(2, 1));
    pair<int, int> p(2, 1);
    if (sPair.find(p) == sPair.end())
    {
        cout << "couldn't find pair : ";
        cout << p.first << " " << p.second << endl;
    }
    else
    {
        cout << "found pair : ";
        cout << p.first << " " << p.second << endl;
    }
    for (auto &p : sPair)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << "size : " << sPair.size() << endl;
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