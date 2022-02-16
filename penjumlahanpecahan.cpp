#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a, b, c, d;
    cin >> a >> b;    
    cin >> c >> d;
    ll gcd = __gcd(b,d);
    ll lcm = b / gcd * d;
    ll f = lcm;
    ll e = (lcm / b * a) + (lcm / d * c);
    gcd = __gcd(e, f);
    cout << e / gcd << " " << f / gcd << endl;
    return 0;
}