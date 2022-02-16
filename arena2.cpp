#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long gold;
    cin >> gold;
    long long saveOp = 0;
    long long tmp = gold;
    if (tmp % 2 == 1){ // cari maksimum punya lawan / pasti kalah
        tmp--;
    }
    // tujuan buat lawan tetap dapet 1 gold (karena ganjil), next step harus ganjil setelah pengambilan, gold setiap loop di while pasti genap
    while(tmp){
        if (tmp == 4){ // base case karena case 2 dan 0 pasti berhasil
            saveOp += 3;
            tmp = 0;
        }else if((tmp / 2) % 2 == 1){
            saveOp += (tmp / 2);
            tmp = (tmp/2) - 1;
        }else{
            saveOp++;
            tmp -= 2;
        }
    }
    if (gold % 2 == 1){ // lawanya dapat optimum, kecuali gold = 3
        saveOp = gold - saveOp;
    }
    cout << saveOp << endl;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
    return 0;
}