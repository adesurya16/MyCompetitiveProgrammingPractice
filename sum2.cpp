#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> maps;
    vector<int> nums;
    int n, sum;
    cin >> n >> sum;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        nums.push_back(num);
        maps[num]++;
    }
    int found = 0;
    for(int i=0;i < n;i++){
        sum -= nums[i];
        maps[nums[i]]--;
        if (maps[sum] != 0){
            cout << "YES" << endl;
            found = 1;
            break;
        }
        sum += nums[i];
        maps[nums[i]]++;
    }
    if (!found) cout << "NO" << endl;
    return 0;
}