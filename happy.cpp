#include <bits/stdc++.h>
using namespace std;

int getNumber(int x){
    int num = x;
    int sum = 0;
    while(num > 0){
        int remind = num % 10;
        sum += (remind*remind);
        num = num / 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> myset;
    int num = n;
    while(num > 1){
        if(myset.find(num) == myset.end()){
            myset.insert(num);
        }else return false;
        num = getNumber(num);
    }
    return true;
}
int main(){
    
    cout << isHappy(19) << endl;
    return 0;
}