#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;


#define gcd(a, b) __gcd(a, b)

const int MOD = 1000000007;

int expo(int m, int n){
    int i = 1;
    while(n--){
        i *= m;
    }
    return i;
}

int fastExpo(int base, int expo){
    base %= MOD;
  int result = 1;
  while (expo > 0) {
    if (expo & 1) result = ((ll)result * base) % MOD;
    base = ((ll)base * base) % MOD;
    expo >>= 1;
  }
  return result;
}



const int maxN = 1000000;

int main(){
    // calculate 3MOD
    int constant3mod = fastExpo(3, MOD - 2);

    vi dpSn = vi(maxN + 1, 0);
    vi mod3n = vi(maxN + 1, 0);

    // store mod3n
    for(int i = 0;i < maxN + 1;i++){
        if (i == 0){
            mod3n[i] = 1;
        }else{
            mod3n[i] = ((ll)mod3n[i - 1] * 3) % MOD;
        }
    }

    // store dpSn
    for(int i=0;i < maxN + 1;i++){
        if (i == 0){
            dpSn[i] = 1;
        }else{
            dpSn[i] = ((ll)(((ll)(((ll)mod3n[i] * mod3n[i]) % MOD) * constant3mod) % MOD) + dpSn[i - 1]) % MOD;
        }
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        // int powers = expo(3, n + 1);
        // cout << powers << " : ";
        // int sum = 0;
        // for(int i=1;i< powers + 1;i++){
        //     int res = i / gcd(i, powers);
        //     cout << res << " ";
        //     if (i % 3 != 0){
        //         sum += res;
        //     }
        // }
        // cout << "SUM : " << sum;
        // cout << endl;
        int num;
        cin >> num;
        int res = ((ll)mod3n[num] * dpSn[num]) % MOD;
        cout << "Kasus #"<< i + 1 <<": ";
        cout << res << endl;        
    }
    return 0;
}