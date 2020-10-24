#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int cookies;
        cin >> cookies;
        long long sum = 0;
        int minNum = INT_MAX;
        for(int i=0;i<cookies;i++){
            int cookie;
            cin >> cookie;
            sum += cookie;
            minNum = min(minNum, cookie);
        }
        cout << sum - (long long)minNum * cookies << "\n";
    }
    return 0;
}