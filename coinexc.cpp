#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        int left, right;
        for(int i=2;i<num;i++){
            if(__gcd(num, i) == 1){
                left = i;
                break;
            }
        }
        for(int i=num - 1; i >= 2;i--){
            if(__gcd(num, i) == 1){
                right = i;
                break;
            }
        }
        cout << right - left << endl;       
    }   
    return 0;
}