#include <bits/stdc++.h>
using namespace std;

void deepCombine(int beg, int n, int k, vector<int> &v){
    if (k == 0){
        // v.size == k
        for(int i=0;i<v.size();i++){
            if(i > 0) cout << " ";
            cout << v[i];
        }
        cout << endl;
    }else{
        for(int i = beg;i < (n - k - 1);i++){
            v.push_back(i + 1);
            deepCombine(i + 1, n, k - 1, v);
            v.pop_back();
        }
    }
}

int main(){
    int n ,k;
    cin >> n >> k;
    // case k = 2
    // for(int i = 0;i < n - 1; i++){
    //     for(int j = i + 1;j < n; j++){
    //         cout << i + 1 << " " << j + 1 << endl;
    //     }
    // }

    vector<int> v (n, 0);
    for(int i = 0;i < n;i++){
        // v.push_back(i);
        v[i] = i;
        cout << v[i] << endl;
    }                      

    deepCombine(0, n, k, v);

    return 0;
}