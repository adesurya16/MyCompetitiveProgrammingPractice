#include <bits/stdc++.h>
using namespace std;
void printVec(vector<int> v){
    for(int num : v){
        cout << num << " ";    
    }
    cout << endl;
}

vector<int> productExceptSelf(vector<int>& nums){
    int l = nums.size();
    vector<int> vprefix;
    int multipleNumber = 1;
    vprefix.push_back(multipleNumber);
    for(int num : nums){
        multipleNumber *= num;
        vprefix.push_back(multipleNumber);
    }
    // printVec(vprefix);
    vector<int> vpostfix;
    multipleNumber = 1;
    vpostfix.push_back(multipleNumber);
    for(int i = l - 1; i >= 0;i--){
        multipleNumber *= nums[i];
        vpostfix.push_back(multipleNumber);
    }
    // printVec(vpostfix);
    for(int i=0;i<l;i++){
        nums[i] = vprefix[i] * vpostfix[l - i - 1];
    }
    return nums;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    printVec(productExceptSelf(v));
    return 0;
}