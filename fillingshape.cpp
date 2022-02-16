// https://codeforces.com/gym/302977/problem/A#
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastPower2(int exp){
    ll power2 = 1;
    return (power2 << exp);
}

int main(){
    int n;
    cin >> n;
    if (n & 1){
        cout << 0 << "\n";
    }else{
        cout << fastPower2(n / 2) << "\n";
    }
    return 0;
}