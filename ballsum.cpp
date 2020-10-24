#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k;
    scanf("%lld %lld", &n, &k);
    while(n != -1 && n != -1){
        if (n == 0 || k == 0){
            printf("0\n");
        }else{
            ll res = ballsum((n < k ? n:k));
            printf("%lld\n", res);
        }
        scanf("%lld %lld", &n, &k);
    }
    return 0;
}