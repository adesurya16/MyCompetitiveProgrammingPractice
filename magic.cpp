#include <bits/stdc++.h>
using namespace std;
int sumOfNumber(int num){
    int sum = 0;
    while(num > 0){
        sum += (num%10);
        num /= 10;
    }
    return sum;    
}

int main(){
    int n;
    cin >> n;
    for(int i=500;i < (n + 500);i++){
        if (i % sumOfNumber(i) == 0){
            cout << i << endl;
        }
    }
    return 0;
}