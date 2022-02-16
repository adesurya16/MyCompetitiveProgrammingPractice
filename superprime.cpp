#include <bits/stdc++.h>
using namespace std;
int main(){
    int max = 10000000;

    
    vector<bool> shieve(max + 1, true);
    shieve[0] = false;
    shieve[1] = false;
    for(int i=2; i <= max;i++){
        if (shieve[i]){
            for(int j = 2*i; j <= max; j+=i){
                shieve[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    int sum = 0;
    for(int i=1;i <= n;i++){
        if(shieve[i] && shieve[i - 2]){
            // cout << i << endl;
            sum++;
        } 
    }
    cout << sum << endl;
    return 0;
}