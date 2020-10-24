#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define FOR(i,n) for( int (i) = 0; (i) < (n);(i)++ )
#define FORN(i, start ,n) for( int (i) = (start); (i) < (n);(i)++ )
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)
int main(){
    // 0 composit/nonprime, 1 prime
    int limit = floor(sqrt(1000000000)) + 1;
    vi prim(limit, 1);
    prim[0] = 0;
    FOR(i, 2, limit){
        if (prim[i] == 1){
            int res = prim[i]*2;
            while(res < limit){
                prim[res] = 0;
                res += prim[i];
            }
        }
    }    
    int x;
    si(x);
    // define prime
    while(x--){

    }
    return 0;
}