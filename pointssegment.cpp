#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<bool> points(m + 1, false);
    int len = m;
    while(n--){
        int l, r;
        cin >> l >> r;
        for(int i = l; i <= r;i++){
            if(!points[i]){
                len--;
                points[i] = true;
            }
        }
    }
    cout << len << endl;
    if (len > 0){
        int size = 0;
        for(int i = 1;i <= m;i++){
            if (!points[i]){
                if (size > 0){
                    cout << " ";
                }
                size++;
                cout << i;
            }
        }    
    }
    cout << endl;
    return 0;
}