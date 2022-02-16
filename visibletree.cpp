#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    vector<vector<int> > trees;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        vector<int> xtree;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            xtree.push_back(x);
        }
        trees.push_back(xtree);
    }
    // bunga
    // |
    // V
    vector<int> bunga;
    for (int j=0;j<n;j++){
        int max = INT_MIN;
        int res = 0;
        for(int i=0;i<n;i++){
            if (trees[i][j] > max){
                max = trees[i][j];
                res++;
            } 
        }
        bunga.push_back(res);
    }

     // lestari
    // -->
    vector<int> lestari;
    for (int i=0;i<n;i++){
        int max = INT_MIN;
        int res = 0;
        for(int j=0;j<n;j++){
            if (trees[i][j] > max){
                max = trees[i][j];
                res++;
            } 
        }
        lestari.push_back(res);
    }
    for(int i = 0;i < bunga.size();i++){
        if (i > 0) cout << " ";
        cout << bunga[i]; 
    }
    cout << endl;
    for(int i=0;i< lestari.size();i++){
        cout << lestari[i] << endl;
    }
    return 0;
}