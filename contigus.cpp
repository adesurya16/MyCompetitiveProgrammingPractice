#include <bits/stdc++.h>
using namespace std;
int findMaxLength(vector<int>& nums){
    // int l = nums.length();
    vector<int> balanced_nums;
    balanced_nums.push_back(0);
    for(int num : nums){
        if (num == 0){
            balanced_nums.push_back(balanced_nums.back() - 1);
        }else{
            balanced_nums.push_back(balanced_nums.back() + 1);
        } // 1    
    }
    unordered_map<int, int> mapping;
    // for(int bnum: balanced_nums){
    //     cout << bnum;
    // }
    // cout << endl;
    int maximum = 0;
    for(int i = 0;i < balanced_nums.size();i++){
        if(mapping.find(balanced_nums[i]) == mapping.end()){
            mapping[balanced_nums[i]] = i;
        }else{
            maximum = max(maximum, i - mapping[balanced_nums[i]]);
            cout << maximum << endl;
        }
    }
    // for(auto map : mapping){
    //     cout << map.first << " : " << map.second << endl;
    // }
    return maximum;
}
int main(){
    vector<int> nums;
    // 1 0 1 0 1 1 1 0
    // 0 1 0 1 0 1 2 3 2
    // 0 -> 0
    // 1 -> 1
    // 0 max = 2
    // 1 max = 2
    // 0 max = 4
    // 1 max = 4
    // 2 -> 
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    cout << findMaxLength(nums) << endl;
    return 0;
}