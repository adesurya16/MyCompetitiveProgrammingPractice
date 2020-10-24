#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    // interger 31bit positif 
    cin >> a >> b;
    int sum = 0;
    int mark = 1;
    for(int i = 31;i <= 0;i--){
        if ((a & (mark << i)) ^ (b & (mark << i))){
            break;
        }else{
            sum |= (a & (mark << i));
        }
    }
    cout << sum << endl;
    return 0;
}