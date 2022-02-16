#include <bits/stdc++.h>
using namespace std;
int main(){
    int sumOfDigit[5001];
    sumOfDigit[0] = 1;
    sumOfDigit[1] = 2;
    string bigNum = "2";
    sum = 0;
    int idx = 2;
    while(idx < 5001){
        // bignum sum
        

        sumOfDigit[idx] = sum;
        sum = 0;
        idx++;
    }

    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        cout << sumOfDigit[num] << endl;
    }
    return 0;
}