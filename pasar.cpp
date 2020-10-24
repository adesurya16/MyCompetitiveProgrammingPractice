#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    int tmp;
    while(b > 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
    
}
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}
int main(){
    // int a,b;
    // cin >> a >> b;
    // cout << lcm(a, b) << endl;
    int n, d;
    cin >> n;
    cin >> d;
    int lcm_ = d;
    n--;
    while(n--){
        cin >> d;
        lcm_ = lcm(d, lcm_);
    //     int x;
    //     cin >> x;
    }
    cout << lcm_ << endl;
    return 0;
}