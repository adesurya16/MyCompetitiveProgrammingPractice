// https://tlx.toki.id/problems/troc-24/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> prefix(n);
    long long func = 0;
    for(int i = 0; i < n;i++){
        int num;
        cin >> num;
        func += num * (-1) * ((i & 1) ? 1 : -1);
        // cout << func << endl;
        prefix[i] = func;
    }
    long long maxim = LLONG_MIN;
    for(int i = 0; i < n - 1;i++){
        long long left = prefix[i];
        long long right = prefix[n - 1] - prefix[i];
        if (i & 1){
            left *= -1;
            right *= -1; 
        }
        maxim = max(maxim, left + right);
    }
    cout << maxim << endl;
    return 0;
}