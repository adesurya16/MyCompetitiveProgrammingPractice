#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin >> n >> k;
    if (k > (n - n/2)){
        cout << 2 * (k - (n - n/2)) << endl; 
    }else{
        cout << 2 * k - 1 << endl;
    }
    return 0;
}