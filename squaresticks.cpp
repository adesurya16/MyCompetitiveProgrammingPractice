#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i < n;i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end(), greater<int>());
    if (n >= 4){
        cout << (long long)nums[3] * nums[3] << endl;
    }else cout << 0 << endl;        
    return 0;
}