#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c){
    return (c == 'a') || (c == 'i') || (c == 'u') || (c == 'e') || (c == 'o');
}

bool isRomaji(string s){
    for(int i = 0;i < s.length();i++){
        if (!isVowel(s[i]) && s[i] != 'n'){
            if(i == (s.length() - 1)) return false;
            if(!isVowel(s[i + 1])) return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    if(isRomaji(s)){
        cout << "YES" << endl;
    }else cout << "NO" << endl;
    return 0;
}