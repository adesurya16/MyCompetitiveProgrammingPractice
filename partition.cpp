// Dp problem, https://leetcode.com/problems/partition-equal-subset-sum/
// similar like subset sum
#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums){
    int sum = 0;
    for(int i : nums){
        sum += i;
    }
    if (sum & 1){
        return 0;
    }
    sum = sum / 2;
    int size = nums.size();
    vector<bool> dp(sum + 1, 0);
    dp[0] = 1;
    // tricky method using O(N) memory complexity
    // common trick usiing O(NxM) and init ascending dp table
    // using 1D array and init value on DP table descending
    for(int i = 0;i < nums.size();i++){
        for(int j = sum;j >= 1;j--){
            if (j >= nums[i]){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
    }
    return dp[sum];
}
int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(8);
    nums.push_back(6);
    nums.push_back(3);
    cout << canPartition(nums) << endl;
    return 0;
}