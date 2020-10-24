#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    
    long long res = 1;
    while(n > 0){
        if (n % 2 == 0){
            res *= 2;
        }
        n = (n >> 1);
    }
    cout << res << endl;
    return 0;
}