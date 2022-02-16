#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int h, m;
        cin >> h >> m;
        cout << 24 * 60 - (h * 60 + m) << endl;
    }
    return 0;
}