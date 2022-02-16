#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> nums(9, 0);
    vector<int> q;
    while(n--){
        int num;
        cin >> num;
        q.push_back(num);
        nums[num]++;
    }
    int idx = -1;
    for(int i=0;i<10;i++){
        if(nums[i] == 1){
            idx = i;
            break;
        }
    }
    if (idx == -1) cout << "-" << endl;
    else{
        for(int i = 0;i < q.size();i++){
            if(q[i] == idx){
                cout << i << endl;
            }
        }
    }
    return 0;
}