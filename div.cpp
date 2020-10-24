#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        long long a,b,c;
        scanf("%lld %lld %lld",&a, &b, &c);
        long long gcd = __gcd(b, c);
        long long lcm = b*c / gcd;
        int sum = 0;
        for(long long i = 2; i < a;i++){
            if (i % b == 0 && i % lcm != 0){
                if (sum > 0){
                    printf(" ");
                }
                printf("%lld", i);
                sum++;
            }
        }
        printf("\n");
    }
    return 0;
}