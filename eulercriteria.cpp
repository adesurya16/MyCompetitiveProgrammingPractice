#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define CASES(n) while(n--)
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ps(x) printf("%s\n", x)

LL power(int num, int p, int mod){
    if (p == 0) return 1;
    LL res = 1;
    LL pow = num;
    while (p > 0){
        if (p & 1) res = ((res % mod) * (pow % mod)) % mod; 
        p >>= 1;
        pow = ((pow % mod) * (pow % mod)) % mod;
    }
    // pll(res);
    return res;
}

int main(){
    int n;
    si(n);
    CASES(n){
        int a, m;    
        si(a);
        si(m);
        if (a == 0 || m == 2){
            ps("YES");
        }else if(power(a, (m - 1)/2, m) == 1){
            ps("YES");
        }else ps("NO");
    }
    return 0;
}