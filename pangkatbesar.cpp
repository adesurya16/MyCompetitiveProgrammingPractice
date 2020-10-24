#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll mod = 1000000;
bool high = false;
ll mpow(ll base, ll exp) {
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) {
        result = ((ll)result * base);
        if (result >= mod){
            high = true;
        }
        result %= mod;
    }  
    exp >>= 1;
    if (exp > 0){
        base = base * base;
        if (base >= mod){
            high = true;
            base %= mod;
        }
    }
  }
  return result;
}

int main(){
    long long a,b;
    scanf("%lld %lld", &a, &b);
    ll res = mpow(a, b);
    ll result2 = res;
    // cout << res << endl;
    string result = "";
    for(int i = 0;i < 6;i++){
        if(res == 0){
            result = "0" + result;
        }else{
            result = to_string(res%10) + result;
            res /= 10;
        }

    }
    if (high){
        cout << result << endl;
    }else{
        cout << result2 << endl;
    }
    return 0;
}