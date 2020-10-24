#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define TC(t) while(t--)
#define maxll 10000000000LL

int main(){
    // cout << maxll << endl;    
    int n;
    cin >> n;
    
    TC(n){
    
        LL val;
        cin >> val;
        LL a = 0;
        LL b = 1;
        if (val == a || val == b){
            cout << "isFibo" << endl;
        }else{
            LL res = a + b;
            while(res < val){
                a = b;
                b = res;
                res = a + b;
            }
            if (res == val){
                cout << "isFibo" << endl;
            }else cout << "isNotFibo" << endl;
        }
    }
    return 0;
}