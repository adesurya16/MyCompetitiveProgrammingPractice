#include <bits/stdc++.h>
using namespace std;

bool isOdd(int odd, int even, int x){
    // bool ODD = true;
    if (odd == 0) return false;
    else if(!(odd & 1)) odd--; //odd should be odd
    // cout << "odd : " << odd << endl;
    if ((odd + even) >= x){
        if((!(x & 1)) && (even == 0)){ //x is odd
            return false;
        }else return true;
    }else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    
    while(cases--){
        int n, x;
        cin >> n >> x;
        int odd = 0, even = 0;
        
        while(n--){
            int num;
            cin >> num;
            if (num & 1){
                odd++;
            }else even++;
        }
        
        if (isOdd(odd, even, x)){
            cout << "YES" << "\n";
        }else cout << "NO" << "\n";
    }

    return 0;
}