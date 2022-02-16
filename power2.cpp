#include <bits/stdc++.h>
using namespace std;
bool isPower2(int x){
    // using bit manipulation, x in the first for special case x = 0 (false)
    return x && (!(x & (x - 1)));
}

int main(){
    int x;
    cin >> x;
    cout << isPower2(x) << endl;
    return 0;
}