#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    int sum = 0;
    while(n--){
        int num;
        cin >> num;
        sum += num;
        arr.push_back(sum);
    }
    // for(int i : arr){
    //     cout << i << " ";
    // }
    // cout << endl;
    
    while(k--){
        int a, b;
        cin >> a >> b;
        int left;
        if ((a - 1) >= 0){
            left = arr[a - 1];
        }else left = 0;
        int right = arr[b];
        cout << right - left << endl;
    }
    return 0;
}