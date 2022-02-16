#include <bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums){
    int size = nums.size();
    vector<int> dp(size + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i=2;i <= size;i++){
        dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    }
    return dp[size];
}

int main(){
    vector<int> sol;
    sol.push_back(1);
    sol.push_back(2);
    sol.push_back(3);
    sol.push_back(1);
    cout << rob(sol) << endl;
    return 0;
}