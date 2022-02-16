#include <bits/stdc++.h>
using namespace std;
void chloe(int num){
    if (num == 1){
        cout << 1;
    }else{
        chloe(num - 1);
        cout <<" "<< num << " ";
        chloe(num - 1);
    }
}
int main(){
    // chloe and sequence
    int num;
    long long k;
    cin >> num >> k;
    // chloe(num);
    // cout << endl;
    int pow = 1;
    int idx = 1;
    while((k + pow) % (pow * 2) != 0){
        pow *= 2;
        idx++;
    }
    cout << idx << endl;
    return 0;
}