#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int m,k;
        cin >> m >> k;
        if ((k - m) <= 0 || (k - m) % 12 != 0){
            cout << "impossible\n";
        }else{
            cout << m + (7 * ((k - m)/12)) << "\n";
        }
    }
    return 0;
}