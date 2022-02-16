#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    int res = 0;
    while(x > 0){
        if (x & 1) res++;
        x = x >> 1;
    }
    cout << res << endl;
    return 0;
}