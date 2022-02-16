#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int number;
        cin >> number;
        if (number==0){
            cout << number << endl;
        }else{
            int res = 0;
            while(number > 0){
                res += (number%10);
                number = number/10;
                if(number > 0) res = res * 10;
            }
            cout << res << endl;
        }
    }
    return 0;
}