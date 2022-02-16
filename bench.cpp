// https://codeforces.com/group/yg7WhsFsAp/contest/355496/problem/P42
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    cin >> m;
    int maxim = INT_MIN;
    // int sum = 0;
    vector<int> arr;
    for(int i=0;i < n;i++){
        int number;
        cin >> number;
        arr.push_back(number);
        // sum += number;
        maxim = max(maxim, number);
        // minim = min(minim, number);
    }
    // cout << "max : " << maxim << endl;
    // sort(arr.begin(), arr.end());
    int kMax = maxim + m;
    int kMin = 0;
    for(int i = 0;i < n;i++){
        if (m <= 0){
            kMin = maxim;
            break;
        } else{
            m -= (maxim - arr[i]);
        }
    }
    // cout << "m : " << m << endl;
    if (kMin == 0){
        if(m % n != 0){
            // cout << "case 1" << endl; 
            kMin = maxim + (m / n) + 1;
        }else{
            // cout << "case 2" << endl; 
            kMin = maxim + (m / n);
        }
    }
    cout << kMin << " " << kMax << endl;
    return 0;
}