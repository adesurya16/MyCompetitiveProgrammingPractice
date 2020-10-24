#include <bits/stdc++.h>
using namespace std;

typedef long L;

#define TC(t) while(t--)
#define FOR(i, a, b) for(int (i) = (a); (i) < (b) ; (i)++)

int main(){
    int n;
    cin >> n;
    TC(n){
        L x;
        cin >> x;
        long sum = 0;
        long res = 1;
        while(x > 0){
            if (x % 2 == 0){
                sum += res;
            }
            x = (x >> 1);
            res = (res << 1);
        }
        cout << sum << endl;
    }
    return 0;
}