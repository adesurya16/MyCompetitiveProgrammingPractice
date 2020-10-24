#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)

int mod = 1000000007;

int mpow(int base, int exp, int mod){
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    
    return result;
}

int main(){
    // pi(mpow(3, 3, mod - 1));
    int x;
    si(x);
    pi(mpow(3, mpow(3, x, mod - 1), mod));
    return 0;
}