#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> grid){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void flood(vector<vector<int>> &grid, int i, int j, int col, int row){
    if ((i < col && i >= 0) && (j  < row && j >= 0) ){
        if(grid[i][j] == 1){
            grid[i][j] = 0;
            flood(grid, i - 1, j, col, row);
            flood(grid, i, j + 1, col, row);
            flood(grid, i + 1, j, col, row);
            flood(grid, i, j - 1, col, row);
        }
    }
}

int numIslands(vector<vector<int>> &grid){
    int column = grid.size();
    int row = grid[0].size();
    int islands = 0;
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            if (grid[i][j] == 1){
                islands++;
                flood(grid, i , j, column, row);
            }
        }
    }
    return islands;
}

int main(){
    int a, b;
    cin >> a;
    cin >> b;
    vector<vector<int>> grid;
    for(int i=0;i<a;i++){
        vector<int> d;
        for(int j=0;j<b;j++){
            int x;
            cin >> x;
            d.push_back(x);
        }
        grid.push_back(d);
    }

    cout << numIslands(grid) << endl;
    return 0;
}