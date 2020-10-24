#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int n, x;
        cin >> n >> x;
        if (n == 1 || n == 2){
            cout << 1 << "\n";
        }else{
            n = n - 2;
            cout << 1 + (n / x) + (int)(n % x > 0) << "\n";
        }
    }
    return 0;
}