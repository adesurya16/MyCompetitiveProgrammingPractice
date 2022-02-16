#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL lcmSum(LL n){
    LL sum = 0;
    for(LL i = 1; i <= n; i++){
        LL gcd = __gcd(i, n);
        LL lcm = (i / gcd) * n;
        cout << lcm << " ";
        sum += lcm;
    }
    return sum;
}

int main(){
    int max = 10;
    while(max--){
        LL l = max;
    // cin >> l;
    cout << "= " << lcmSum(l) << endl;
    }
    
    return 0;
}