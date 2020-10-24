#include <bits/stdc++.h>
using namespace std;
bool cmp(string s1, string s2){
    return (s1.length() < s2.length()) || (s1.length() == s2.length() && s1.compare(s2) < 0);
}
int main(){
    int d;
    vector<string> vs;   
    scanf("%d", &d);
    while(d--){
        string s;
        cin >> s;
        vs.push_back(s);
    }
    sort(vs.begin(), vs.end(), cmp);
    for(string s: vs){
        cout << s << "\n";
    }
    return 0;
}
