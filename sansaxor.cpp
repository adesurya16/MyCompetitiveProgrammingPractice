#include <bits/stdc++.h>
using namespace std;
#define TC(t) while(t--)
#define FOR(i,a,b) for(int (i) = (a) ;(i) < (b) ;(i)++)
int main(){
    int t;
    cin >> t;
    TC(t){
        int n;
        cin >> n;
        if (n % 2 == 0){
            FOR(i, 0, n){
                int val;
                cin >> val;
            }
            cout << 0 << endl;
        }else{
            int res = 0;
            FOR(i, 0, n){
                int val;
                cin >> val;
                if ((i+1) % 2 != 0){
                    res ^= val;
                }
            }
            cout << res << endl;
        }
        
    }
    return 0;
}