#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr){
    for(int i=0;i < arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printDP(vector<vector<bool>> dp, int n, int target){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= target; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

// temukan semua pembagi kecuali bilangan itu sendiri
vector<int> getPembagiWajar(int a){
    vector<int> sol;
    sol.push_back(1);
    for(int i = 2;i * i <= a ;i++){
        if(a % i == 0){
            if((i * i) == a){
                sol.push_back(i);
            }else{
                sol.push_back(i);
                sol.push_back(a / i);
            }
        }
    }
    // cout << a << " : ";
    // printArr(sol);
    return sol;
}


// dp problem subset sum
bool subsetSum(vector<int> arr, int target){
    int n = arr.size();
    // cout << target << " : ";
    // printArr(arr);
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
    
    for(int i = 0;i <= target;i++){
        dp[0][i] = false;
    }

    for(int i = 0;i <= n;i++){
        dp[i][0] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){
            if (j < arr[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    
    // printDP(dp, n, target);

    return dp[n][target];
}

int solution(int a, int b){
    for(int i = b; i >= a;i--){
        if(!subsetSum(getPembagiWajar(i), i)){
            // cout << i << endl;
            return i - a;
        }
    }
    return -1;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << solution(a, b) << endl;
}