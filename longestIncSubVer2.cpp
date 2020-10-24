// Classic Problem Longest Increasing Subsequence (non - decrasing)
// approach 2 using DP iterative (bottom - up)
// we can use DP rekursif (top - down) without memoization but the time complexity around 2^n (tree spawn)
// using brutoforce/exhaustedsearch to generate all subset and validate it one by one take the longest 2^n too
// Time Complexity O(n^2)
// Space Cmplexity O(n) for better visualitation using 2CN vector
// example LIS from [-1 3 4 5 2 2 2 2] = 5 (-1,2,2,2,2)
#include <bits/stdc++.h>
using namespace std;

int maxVec(vector<int> v){
    int maxim = INT_MIN;
    for(int i : v){
        maxim = max(maxim, i);
    }
    return maxim;
}

int main(){    
    // vector<vector<int>> visual; //only better visualitation using O(N^2) space
    int size;
    cin >> size;
    vector<int> seq(size);
    for(int i = 0;i < size;i++){
        int num;
        cin >> num;
        seq[i] = num;
        // cout << num << " ";
    }
    // cout << "\n";

    // i,j pointer like find combination of 2 from N
    // vector<int> one(1, 1); // pointer 1,1
    // visual.push_back(one);
    // int ans;
    // for(int j = 1; j < size;j++){
    //     int maxJ = 1;
    //     int idx = j - 1;
    //     vector<int> vIdx = visual[idx];
    //     vector<int> vIdx2;
    //     for(int i = 0;i <= j;i++){
    //         //push_back?
    //         vIdx2.push_back(vIdx[i]);
    //         if(seq[j] >= seq[i]){
    //             maxJ = max(maxJ, 1 + vIdx[i]);
    //         }
    //     }
    //     vIdx2.push_back(maxJ);
    //     visual.push_back(vIdx2);
    //     if (j == size - 1){
    //         ans = maxJ;
    //     }
    // }
    // cout << ans << "\n";
 
    // using O(N) space
    // ans = 1;
    vector<int> dp(size, 1);
    // cout << "running" << endl;
    for(int j = 1; j < size; j++){
        int maxJ = dp[j];
        for(int i = 0;i < j; i++){
            if(seq[j] >= seq[i]){
                // cout << seq[j] << " " << seq[i] << "\n";
                maxJ = max(maxJ, (dp[j] + dp[i]));
            }
            // cout << dp[i] << " ";
        }
        dp[j] = maxJ;
        // cout << dp[j] << "\n";
    }
    cout << maxVec(dp) << "\n";
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}