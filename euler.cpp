#include <bits/stdc++.h>
using namespace std;
long long expMod(long long a,long long b, long long mod){
    long long res = 1;
    long long exp = ;
    while(b){
        if (b % 2 == 1){
            res = 
        }
    }
}
int main(){
    int x;
    scanf("%d", &n);
    while(n--){
        long long a,b;
        scanf("%dll %dll", &a, &b);
        if (a == 0){
            printf("YES\n");
        }else if(expMod(a, (b-1)/2, b) == 1){
            printf("YES\n");
        }else printf("NO\n");
    }
    return 0;
}