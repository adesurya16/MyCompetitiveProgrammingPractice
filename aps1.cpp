#include <bits/stdc++.h>
using namespace std;
#define FORN(i, n) for(int (i) = 0; (i) < (n) ; (i)++)
#define FOR(i, j, k) for(int (i) = j; (i) < (k) ; (i)++)
#define cases(x) while((x)--)

typedef long long ll;

const int maxN = 1000000;

int main(){ 
    
    ll comp[maxN + 1];
    FORN(i, maxN + 1){
        comp[i] = 0;
    }
    FOR(i, 2, maxN + 1){
        if (comp[i] == 0){
            int res = i;
            while(res < (maxN + 1)){
                if (comp[res] == 0) comp[res] = i;
                res += i;
            }
        }
    }


    FOR(i, 2, maxN + 1){
        comp[i] += comp[i - 1];
    }

    int n;
    scanf("%d", &n);
    cases(n){
        int x;
        scanf("%d", &x);
        printf("lld\n", comp[x]);
    }
    return 0;
}