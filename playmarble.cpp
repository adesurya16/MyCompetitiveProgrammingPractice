#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int x;
    cin >> x;
    while(x > 0){
        cout << 5 + (x - 1) * 7 + (x - 1)*(x - 2)*3 / 2 << "\n";
        cin >> x;
    }
    return 0;
}