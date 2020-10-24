#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int INF = 1000000005;
#define FOR(a, b, c) for ( int (a) = (b); (a) < (c); (a)++)
#define FORN(a, b, c) for( int (a) = (b); (a) <= (c); (a)++)
#define FORD(a, b, c) for( int (a) = (b); (a) >= (c); (a)--)
#define TC(t) while(t--)
#define endl '\n'
#define watch(x) cout << (#x) << " : " << (x) << endl

#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)

int main(){
    int x;
    si(x);

    int n;
    si(n);
    vi coin(n);
    FOR(i, 0, n){
        si(coin[i]);
    }
    vvl dp(n, vl(x + 1, 0));
    // FOR(i, 0, n){
    //     FOR(j, 0, x + 1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    FOR(i, 0, n){
        FOR(j, 0, x + 1){
            if (j == 0){
                dp[i][j] = 1;
            }else if(i == 0){
                if (j % coin[i] == 0) dp[i][j] = 1;
            }else{
                if ((j - coin[i]) < 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]];
            }
        }
    }
    // FOR(i, 0, n){
    //     FOR(j, 0, x + 1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    pl(dp[n - 1][x]);
    return 0;
}