#include <bits/stdc++.h>
using namespace std;
int main(){
    int sum; // sum >= 3
    cin >> sum;
    int limit = (sum / 2);
    while(limit > 1){
        if (__gcd(limit, sum - limit) == 1) break;
        limit --;
    }
    cout << limit << " " << sum - limit << endl;
    return 0;
}