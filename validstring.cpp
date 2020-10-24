#include <bits/stdc++.h>
using namespace std;
bool checkValidParenthesisString(string str, int idx, stack<char> s){
    if (idx == str.length()){
        if(s.empty()){
            return true;
        }else return false;
    }else{
        if(str[idx] == '('){
            s.push(str[idx]);
            return checkValidParenthesisString(str, idx + 1, s);
        }else if (str[idx] == ')'){
            if (s.empty()){
                return false;
            }else{
                // char c = s.top();
                s.pop();
                return checkValidParenthesisString(str, idx + 1, s);
            }
        }else{
            string str1 = str;
            str1[idx] = ')';
            string str2 = str;
            str2[idx] = '(';
            return checkValidParenthesisString(str1, idx, s) || checkValidParenthesisString(str2, idx, s) || checkValidParenthesisString(str, idx + 1, s);
        }
    }
}

bool checkValidString(string s){
    int l = s.length();
    int start = 0;
    // double stacks ( and *
    stack<int> s_par;
    stack<int> s_star;
    for(char c : s){
        if (c == '('){
            s_par.push(start);
        }else if(c == '*'){
            s_star.push(start);
        }else{
            if (!s_par.empty()){
                s_par.pop();
            }else if(!s_star.empty()){
                s_star.pop();
            }else return false;
        }
        start++;
    }
    if (!s_par.empty()){
        if(s_star.empty()){
            return false;
        }else{
            while(!s_par.empty() && !s_star.empty()){
                int par = s_par.top();
                int star = s_star.top();
                if (star > par){
                    s_par.pop();
                    s_star.pop();
                }else return false;
            }
            if(s_par.empty()){
                return true;
            }else return false;
        }
    }else return true;
}


int main(){
    string s;
    cin >> s;

    // stack<char> sc;
    // for(char i : s){
    //     sc.push(i);
    // }
    // while(!sc.empty()){
    //     char i = sc.top();
    //     sc.pop();
    //     cout << i;
    // }
    // if (checkValidString(s)){
    //     cout << "True" << endl;
    // }else cout << "False" << endl;
    cout << checkValidString(s) << endl;
    return 0;  
}