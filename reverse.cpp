#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    while(n--){
        cin >> vec[n];
    }
    for(int i=0;i<vec.size();i++){
        if (i > 0){
            cout << " ";
        }
        cout << vec[i];
    }
    cout << endl;
    return 0;
}