#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define TC(t) while(t--)
#define watch(x) cout << "(checkpoint) " << (#x) << " : " << (x) << endl



int main(){
    int t;
    cin >> t;
    TC(t){
        LL x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // watch(x1);
        // cout << __gcd(x1, y1) << endl;
        if (__gcd(x1, y1) == __gcd(x2, y2) ){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
    }
    return 0;
}