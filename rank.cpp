#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> numbers, int target, int left, int right){
    // must be found
    // cout << target << endl;
    while(left < right){
        // cout << left << " - " << right << endl;
        int mid = (left + right) / 2;
        // cout << mid << endl;
        if (numbers[mid] <= target){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return right + 1;
}

int main(){
    int n;
    cin >> n;
    vector<int> numbers;
    int thomasScore = -1;
    while(n--){
        int num[4];
        cin >> num[0] >> num[1] >> num[2] >> num[3];
        if (thomasScore == -1){
            thomasScore = num[0] + num[1] + num[2] + num[3];
        }
        // cout << num[0] + num[1] + num[2] + num[3] << endl;
        numbers.push_back(num[0] + num[1] + num[2] + num[3]);
    }
    sort(numbers.begin(), numbers.end(), greater<int>());
    // for(int num : numbers){
    //     cout << num << endl;
    // }
    // cout << numbers.size() << endl;
    // cout << thomasScore << endl;
    cout << binarySearch(numbers, thomasScore, 0, numbers.size() - 1) << endl; 
    return 0;
}