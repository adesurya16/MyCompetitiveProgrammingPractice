#include <bits/stdc++.h>
using namespace std;
#define TC(x) while(x--)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    TC(t){
        string s;
        cin >> s;
        int sum = 0;
        for(char c: s){
            int dig = ((int)c - (int)'1') + 1;
            sum += dig;
        }
        cout << sum << "\n";
    }
    return 0;
}