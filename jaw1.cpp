#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)
#define FOR(i, n) for(int (i) = 0 ; (i) < (n) ; (i)++)

int main(){
    int x, y;
    si(x);
    si(y);
    int tab[x][y];
    FOR(i, x){
        FOR(j, y){
            si(tab[i][j]);
        }
    }
    FOR(i, x){
        FOR(j, y){
            if(tab[i][j] > 0){
                   
            }
        }
    }
    return 0;
}