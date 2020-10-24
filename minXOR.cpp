#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    if(k == 1){
        cout << n << "\n";
    }
    if(n & 1){ //odd
        if(k >= 3){
            cout << 1 << "\n";
        }else{ // k == 2 
            // for(int i=1;i<=(n/2);i++){
            //     cout << i << " : " << (i ^ (n - i)) << "\n";
            // }
            cout << ((n - (n/2)) ^ (n/2)) << "\n";
        }
    }else cout << 0 << "\n";
    return 0;
}