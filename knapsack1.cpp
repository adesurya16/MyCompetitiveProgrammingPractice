#include <bits/stdc++.h>
using namespace std;

// knapsack using DP top down rekursif without memoization

int knapsack(int w, vector<int> wt, vector<int> valt, int n, vector<vector<bool>> &dp){
    if(dp[n][w] != INT_MIN){
        return dp[n][w];
    }
    int res;
    if (w == 0 || n == 0){
        res = 0;
    }else if(wt[n - 1] > w){
        // cout << "1" << endl;
        res = knapsack(w, wt, valt, n - 1, dp);
    }else{
        // cout << "2" << endl;
        res = max(valt[n - 1] + knapsack(w - wt[n - 1], wt, valt, n - 1, dp), 
        knapsack(w, wt, valt, n - 1, dp));
    }
    dp[n][w] = res;
    return  res;
}

// knapsack using DP top down rekursif with memoization


int main(){
    vector<int> valt{60, 100, 120};
    vector<int> wt{10, 20, 30};

    int w = 50;
    int n = wt.size();
    vector<vector<bool>> dp(n, vector<bool>(w, INT_MIN));

    cout << knapsack(w, wt, valt, n) << endl;
    return 0;
}