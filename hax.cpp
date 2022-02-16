#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(char i: s){
        if (i == 'a') cout << '4';
        else if(i == 'i') cout << '1';
        else if(i == 'e') cout << '3';
        else if(i == 'o') cout << '0';
        else if(i == 's') cout << '5';
        else cout << i;
    }
    cout << endl;
    return 0;
}