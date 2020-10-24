#include <bits/stdc++.h>
using namespace std;

typedef long L;

#define TC(n) while(n--)

int main(){
    int a,b;
    L sum = 0;
    cin >> a >> b;
    TC(b){
        L c, d, e;
        cin >> c >> d >> e;
        sum += (d - c + 1) * e;
    }
    cout << sum / a << endl;
    return 0;
}