#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calculate(ll n){
    // xor 1 to n
    if (n == 0){
        return 0;
    }

    if (n % 4 == 1){
        return 1;
    }else if(n % 4 == 2){
        return n + 1;
    }else if(n % 4 == 3){
        return 0;
    }else{
        return n;
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
       ll left, right;
       cin >> left >> right;
       ll res = calculate(left - 1) ^ calculate(right);
       cout << res << "\n";  
    }
    
    return 0;
}