#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b){
    int gcd = __gcd(a, b);
    return a / gcd * b;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int a,b,c;
        cin >> c >> a >> b;
        int lcm_ = lcm(a, b);
        cout << (int)(c / a) - (int)(c / lcm_) << " " << (int)(c / b) - (int)(c / lcm_) << endl;
    }
    return 0;
}