#include <bits/stdc++.h>
using namespace std;

// find square root a number using binary search

int mySqrt(int x){
    if (x == 0){
        return 0;
    }
    int pLeft = 1;
    int pRight = x;
    while (pLeft <= pRight){
        mid = (pLeft + pRight) / 2;
        if (mid * mid == x){
            return mid;
        }else if(mid * mid < x){
            pLeft = mid + 1;
        }else{
            pRight = mid - 1;
        }        
    }
    return pLeft - 1; //?
}

int main(){
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;
}