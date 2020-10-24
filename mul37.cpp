#include <bits/stdc++.h>
using namespace std;
// 3 6 9 12 (3 + 3*|n/3|| * |n/3|/2)
// 7 14 21 
int main(){
    int n;
    cin >> n;
    if (n <= 50){
        int sum3 = 3 * (1 + (n / 3)) * (n / 3) / 2;
        int sum7 = 7 * (1 + (n / 7)) * (n / 7) / 2;
        int sum21 = 21 * (1 + (n / 21)) * (n / 21) / 2;
        cout << sum3 + sum7 - sum21 << endl;
    }else{
        cout << "error > 50" << endl;
    }
    return 0;
}