// https://codeforces.com/gym/302977/problem/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<bool> typing(26, false); // 'a' - 'z', 0 - 25
    for(int i = 0;i < k;i++){
        char c;
        cin >> c;
        typing[c - 'a'] = true;
    }

    // find the pattern
    int start = 0;
    long long sum = 0;
    for(int i = 0;i < n;i++){
        if(typing[s[i] - 'a']){
            start++;
        }else{
            sum += (long long)start*(start+1)/2;
            start = 0;
        }
    }
    sum += (long long)start*(start+1)/2;
    cout << sum << "\n";
    return 0;
}