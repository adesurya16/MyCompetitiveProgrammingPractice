#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    for(int i =0;i < x;i++){
        int n;
        cin >> n;
        int min;
        int sum = 0;
        for(int j = 0;j < n;j++){
            int nCake;
            cin >> nCake;
            if (j == 0){
                min = nCake;
            }else if (nCake < min){
                min = nCake;
            }
            sum += nCake; 
        }
        cout << sum - n*min << endl;
    }
}