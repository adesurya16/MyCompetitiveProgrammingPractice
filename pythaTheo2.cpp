#include <bits/stdc++.h>
using namespace std;
bool isSquare(int num){
    return num == (trunc(sqrt(num)) * trunc(sqrt(num))); 
}

int main(){
    int n;
    cin >> n;
    // cout << isSquare(n) << endl;
    int sum = 0;
    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < n + 1;j++){
            if (isSquare(i * i + j * j)){
                sum++;
            }
        }
    } 
    cout << sum /  2 << endl;
    return 0;
}