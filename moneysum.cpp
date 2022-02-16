// https://cses.fi/problemset/task/1745
#include <bits/stdc++.h>
using namespace std;


void solution(vector<int> vec){
    // using DP approach
    int sum = 0;
    for(int i : vec){
        sum += i;
    }
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for(int i : vec){
        // cout << i << " : ";
        for(int j = sum; j >= 0; j--){
            if ((j - i) >= 0 && (j - i) <= sum && !dp[j]){
                dp[j] = dp[j - i];
            }        
        }
        // deleted
        // for(int j = 1 ; j < sum + 1;j++){
        //     cout << dp[j] << " ";
        // }
        // cout << endl;
    }
    int s = 0;
    for(int j = 1 ; j < sum + 1;j++){
        if (dp[j]) {
            s++;
            if (s > 1) cout << " ";
            cout << j;
        }    
    }
    cout << endl;
}

void solutionBF(vector<int> vec){
    // using brute force (bitmask)
    int sum = 0;
    for(int i : vec){
        sum += i;
    }
    int n = vec.size();
    // cout << n << endl;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for(int i = 0;i < (1<<n);i++){
        // cout << i << " : ";
        int sum2 = 0;
        for(int j = 0; j < n; j++){
            // cout << j << " ";
            if (i & (1 << j)){
                // cout << "(1) ";
                sum2 += vec[j];
            }
            // }else cout << "(0) ";
        }
        // cout << endl;
        // cout << sum2 << endl;
        dp[sum2] = true;
    }

    int s = 0;
    for(int j = 1 ; j < sum + 1;j++){
        if (dp[j]) {
            s++;
            if (s > 1) cout << " ";
            cout << j;
        }    
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    int sum = 0;
    for(int i=0;i < n;i++){
        int num;
        cin >> num;
        vec[i] = num;
        sum += vec[i];
    }
    solution(vec);
    solutionBF(vec);    
    
    return 0;
}