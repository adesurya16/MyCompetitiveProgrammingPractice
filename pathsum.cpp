#include <bits/stdc++.h>
using namespace std;
int demo = 0;
void printVector(vector<vector<int>> v){
    for(vector<int> col:v){
        for(int row:col){
            cout << row << " ";
        }
        cout << endl;
    }
}

int minPathSumMem(vector<vector<int>> grid, int i, int j, map<pair<int, int>, int> &minmap){
    if (minmap.find({i, j}) != minmap.end()){
        cout << ++demo << endl;
        return minmap[{i, j}];
    }
    if (grid.size() - 1 == i && grid[0].size() - 1 == j){
        return grid[i][j];
    }else{
        const int k = 1e9 + 5;
        int c = grid.size();
        int r = grid[0].size();
        int m = min((i == c - 1)?k:minPathSumMem(grid, i + 1, j, minmap), (j == r - 1)?k:minPathSumMem(grid, i, j + 1, minmap));
        minmap[{i, j}] = grid[i][j] + m;
        return grid[i][j] + m;
    }
}

int minPathSum(vector<vector<int>> grid){
    int height = grid.size();
    int width = grid[0].size();
    vector<vector<int>> dp(height, vector<int>(width));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if (i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }else {
                if (i == 0){
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                }else if(j == 0){
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                }else dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i - 1][j]);
            }
        }
    }
    return dp[height - 1][width - 1];
}

int main(){
    int height, width;
    cin >> height >> width;
    vector<vector<int>> v;
    for(int i=0;i<height;i++){
        vector<int> vc;
        for(int j=0;j<width;j++){
            int x;
            cin >> x;
            // v[i][j] = x;
            vc.push_back(x);
        }
        v.push_back(vc);
    }
    cout << minPathSum(v) << endl;
    map<pair<int, int>, int> minmap;
    // minmap[make_pair(0,0)] = v[0][0];
    cout << minPathSumMem(v, 0, 0, minmap) << endl;
    return 0;
}