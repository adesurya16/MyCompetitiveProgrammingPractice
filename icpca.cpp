#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define cases(x) while(x--)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)

void test(){
    ll num;
    sl(num);
    ll score = 0;
    while(num > 0){
        if(num & 1){ // mr chenek's turn, num si odd 
            num--;
            score++;
        }else{
            num >>= 1;
            score += num;
            
        }
        if (num > 0){ // oppenent's turn
            if(num & 1){
                num--;
            }else num >>= 1;
        }
    }
    pl(score);
}

int main(){
    int x;
    si(x);
    cases(x){
        test();
    }
    return 0;
}