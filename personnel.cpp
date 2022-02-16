#include <bits/stdc++.h>
using namespace std;

unsigned long long fac(int n){
    unsigned long long res = 1;
    for(int i = 1;i < n + 1;i++){
        res *= i;
    }
    return res;
}

unsigned long long combi(int n, int k){
    // k = 5, 6, 7
    unsigned long long numerator = 1; // up

    unsigned long long denominator = fac(k); // down

    for(int i = n - k + 1;i < n + 1; i++){
        numerator *= i;
        unsigned long long gcd =  __gcd(numerator, denominator);
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
    return numerator / denominator;
}

int main(){
    int n;
    cin >> n;
    cout << combi(n, 5) + combi(n, 6) + combi(n, 7) << endl;
    return 0;
}