#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}
int main(){
    vector<int> upcase(26, 0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(char c : s){
        upcase[c - 'A']++;
    }
    // for(int i = 0; i < 26;i++){
    //     cout << upcase[i] << endl;
    // }
    vector<pair<int, int>> arr(26);
    for(int i=0;i < 26;i++){
        // cout << upcase[i] << endl;
        arr[i] = make_pair(i, upcase[i]);
    }
    // for(int i=0;i < 26;i++){
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }

    sort(arr.begin(), arr.end(), comp);     
    long long sum = 0;
    for(int i=0;i < 26;i++){
        if (arr[i].second <= k){
            k -= arr[i].second;
            sum += (long long)arr[i].second * arr[i].second;
        }else{
            sum += (long long)k * k;
            k = 0;
        }
        if (k == 0) break;
    }
    cout << sum << endl;
    return 0;
}