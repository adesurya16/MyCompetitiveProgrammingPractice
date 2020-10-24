#include <bits/stdc++.h>
using namespace std;
bool backspace(string S, string T){
    string St = "";
    for(int i = 0;i < S.length();i++){
        if (S[i] == '#'){
            if (St.length() > 0) St.pop_back();
        }else St += S[i]; 
    }
    string Tt = "";
    for(int i = 0;i < T.length();i++){
        if (T[i] == '#' ){
            if (Tt.length() > 0) Tt.pop_back();
        }else Tt += T[i];
    }
    cout << St << endl;
    cout << Tt << endl;
    return (St.compare(Tt) == 0);    
}


int main(){
    cout << backspace("y#fo##f","y#f#o##f") << endl;
    // string s = "ade";
    // cout << s[s.length() - 1] << endl;
    // s.pop_back();
    // cout << s[s.length() - 1] << endl;
    return 0;
}