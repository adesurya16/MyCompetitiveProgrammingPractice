#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for( int (i) = 0; (i) < (n) ; (i)++ )

#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)

int maxN = 500;
int maxK = 50000;



int main(){
    int n;
    si(n);
    int coin[n];
    FOR(i, n){
        si(coin[i]);
    }
    int k;
    si(k);

    int tab[n][k + 1];
    
    FOR(i , n){
        FOR(j, k + 1){
            if (j == 0){
                tab[i][j] = 0;
            }else{
                if ((j - coin[i]) < 0){
                    if (i == 0) tab[i][j] = INT_MAX;
                    else tab[i][j] = tab[i - 1][j];
                }else if(i == 0){
                    if(tab[i][j - coin[i]] == INT_MAX){
                        tab[i][j] = INT_MAX;
                    }else{
                        tab[i][j] = tab[i][j - coin[i]] + 1;
                    }
                }else{
                    if (tab[i][j - coin[i]] == INT_MAX){
                        tab[i][j] = tab[i - 1][j];
                    }else tab[i][j] = min(tab[i - 1][j], tab[i][j - coin[i]] + 1);
                }
            }
        }
    }
    
    // FOR(i ,n){
    //     FOR(j, k + 1){
    //         cout << tab[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // pi(INT_MAX);
    if (tab[n - 1][k] == INT_MAX){
        pi(-1);
    }else pi(tab[n - 1][k]);
    return 0;
}