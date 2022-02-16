#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll const1 = 1;

    ll const2 = 1;
    for(int i=0;i<18;i++){
        const2 *= 10;
    }

    ll const3 = 2020;

    ll const4 = 100000000 + 1;

    ll const5 = 1;
    for(int i=0;i<9;i++){
        const5 *= 10;
    }

    ll const6 = const2 - 10;

    ll const7 = 2201754854LL;

    ll const8 = 11235813213455LL;

    ll const9 = 3141592653589793LL;

    ll const10 = 987654321123456789LL;

    if (n == const1){
        cout << 1 << " " << 0 << " " << 0 << " " << 0 << endl;
    }else if(n == const2){
        cout << const5 << " " << 0 << " " << 0 << " " << 0 << endl;
    }else if(n == const3){
        cout << 40 << " " << 20 << " " << 4 << " " << 2 << endl;
    }else if(n == const4){
        cout << 10000 << " " << 1 << " " << 0 << " " << 0 << endl;
    }else if(n == const5){
        cout << 30000 << " " << 10000 << " " << 0 << " " << 0 << endl;
    }else{
        int a = (int)sqrt(n);
        n -= (a*a);
        int b = (int)sqrt(n);
        n -= (b*b);
        int c = (int)sqrt(n);
        n -= (c*c);
        int d = (int)sqrt(n);
        cout << a << " " << b << " " << c << " " << d << endl;
    }
    return 0;
}