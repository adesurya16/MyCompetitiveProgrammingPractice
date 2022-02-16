#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums){
    return 0;
}

long long maxProductBF(vector<int>& nums){
    int n = nums.size();
    long long maximum = LLONG_MIN;
    for(int i = 0;i < n; i++){
        long long product = nums[i];
        maximum = max(product, maximum);
        for(int j = i + 1; j < n; j++){
            product *= nums[i];
            maximum = max(product, maximum);
        }
    }
    return maximum;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    while(n--){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    return 0;
}