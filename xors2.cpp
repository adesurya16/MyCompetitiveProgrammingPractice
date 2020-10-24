#include <bits/stdc++.h>
using namespace std;
long long findPrefixXor(long long a){
    if (a % 4 == 0){
        return a;
    }else if (a % 4 == 1){
        return 1;
    }else if (a % 4 == 2){
        return a + 1;
    }else return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
       long long a,b;
       scanf("%lld %lld", &a, &b);
       if (a == b) printf("%lld\n", a);
       else printf("%lld\n", findPrefixXor(b) ^ findPrefixXor(a - 1)); 
    }
    return 0;
}