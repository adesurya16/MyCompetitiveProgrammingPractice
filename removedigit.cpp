#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k){
    stack<char> s;
    int idx = 0;
    while(k < 0){
        if (num[idx] == 0 && s.empty()){
            idx++;
        }else if(s.empty() && idx < num.length()){
            s.push(num[idx]);
        }else{
            
        }
}
int main(){
    int k;
    string s;
    cin >> k;
    cin >> s;

    return 0;
}