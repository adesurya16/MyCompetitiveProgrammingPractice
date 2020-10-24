#include <bits/stdc++.h>
using namespace std;
int main(){
    int r = -2;
    r = r % 7;
    cout << r << endl;
    string s = "abcdefg";
    cout << s << endl;
    rotate(s.begin(), s.begin() + (s.length() - r), s.end());
    cout << s << endl;
    pair<int, int> p;
    p.first = 2;
    p.second = 3;
    // cout << p.first << endl;
    pair<int, int> p2;
    p2.first = 2;
    p2.second = 3;
    map<pair<int, int>,int> mp;
    mp[p] = 1;
    cout << mp[p] << endl;
    mp[p2] = 2;
    cout << mp[p] << endl;
    if (p == p2){
        cout << "sama" << endl;
    }else cout << "tidak" << endl;
    // if (p == p2) cout << "sama" << endl;
    return 0;
}