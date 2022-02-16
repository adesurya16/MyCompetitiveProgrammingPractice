#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] == target){
                return mid;
            }else if (target > nums[mid]){
                left = mid + 1;
            }else right = mid - 1;
        }
        return -1;
    }
int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (target > nums[right]){
            return right + 1;
        }
        while(left < right){
            int mid = (right + left) / 2;
            // cout << left << " " << right << endl;
            if (nums[mid] >= target){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return right;
    }
int main(){
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(12);
    int target;
    cin >> target;
    // cout << search(nums, target) << endl;
    cout << searchInsert(nums, target) << endl;
    return 0;
}