#include <bits/stdc++.h>
using namespace std;
int minim(int a, int b){
    if (a > b) return b;
    return a;
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        int max = INT_MIN;
        int min = INT_MAX;
        int idxMax = -1;
        int idxMin = -1;
        for(int i = 0;i < n;i++) {
            int num;
            cin >> num;
            if(num < min){
                min = num;
                idxMin = i;
            }
            if(num > max){
                max = num;
                idxMax = i;
            }    
        }
        cout << idxMax << " " << idxMin << endl;
        if (idxMax < idxMin){
            swap(idxMax, idxMin);
        }
        cout << minim(idxMax, minim(idxMin + (n - idxMax + 1), n - idxMin + 1)) << endl;
    }
    return 0;
}