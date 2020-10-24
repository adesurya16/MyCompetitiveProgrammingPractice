#include <bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x);
int revInt(int x){
    int res = 0;
    while (x > 0){
        res += (x % 10);
        x /= 10;
        if (x > 0) res *= 10;
    }
    return res;
}

int main(){
    int cases;
    si(cases);
    while(cases--){
        int num1, num2;
        si(num1);
        si(num2);
        pi(revInt(revInt(num1) + revInt(num2)));
    }
    return 0;
}