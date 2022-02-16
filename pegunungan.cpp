#include <bits/stdc++.h>
using namespace std;
void print(int n){
    for(int i=0;i<n;i++){
        cout << "*";
    }
    cout << endl;
}

void level(int l){
    if(l == 1){
        print(l);
    }else{
        level(l - 1);
        print(l);
        level(l - 1);
    }
}

int main(){
    int n;
    cin >> n;
    level(n);
    return 0;
}