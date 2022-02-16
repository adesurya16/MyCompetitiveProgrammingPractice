// https://tlx.toki.id/problems/troc-24/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arrA(n);
    vector<int> arrB(n);
    for(int i = 0;i < n;i++){
        cin >> arrA[i];
    }
    for(int i =0;i < n;i++){
        cin >> arrB[i];
    }
    int k = 0;
    while(n--){
        if (arrA[n] == arrB[n]) k++;
    }
    cout << k << endl;
    return 0;
}