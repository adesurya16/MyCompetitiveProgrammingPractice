#include <bits/stdc++.h>
using namespace std;
// [4,5,6,1,2,3]
int search(vector<int> nums, int target){
    int l = 0;
    int r = nums.size() - 1;
    while(l <= r){
        int mid = l + (r - l)/2;
        // cout << l << " " << mid << " " << r << endl;
        if (nums[mid] == target){
            return mid;
        }
        if(nums[mid] >= nums[l]){
            if(target < nums[mid] && target >= nums[l]){
                r = mid - 1;
            }else l = mid + 1;
        }else{
            if (target > nums[mid] && target < nums[l]){
                l = mid + 1;
            }else r = mid - 1; 
        }
    }
    return -1;       
}
int main(){
    int num = 7;
    vector<int> nums;
    while(num--){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int target;
    cin >> target;
    cout << search(nums, target) << endl; // idx or -1
    return 0;
}