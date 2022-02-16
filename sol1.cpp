#include <bits/stdc++.h>
using namespace std;

// bruto force solution

// assume N integer/long long range

// N at least contain one '5' digit

// M consist of at least two digits

long long delete1(string s, int dig){
    s.erase(dig - 1, 1);
    long long res = stoll(s);
    return res;
}

long long solution(long long N){
    // positive case
    // cout << s << endl;
    // cout << size << endl;
    if (N > 0){
        string s = to_string(N);
        int size = s.length();
        // find maximum
        long long max = 0;
        for(int i = 0;i < size;i++){
            if (s[i] == '5'){
                long long num = delete1(s, i + 1);
                // cout << num << endl;
                if (num > max){
                    max = num;
                }
            }
            
        }
        return max;
    }else{
        // find minimum
        N = -N;
        
        string s = to_string(N);
        int size = s.length();
        long long min = INT_MAX;
        for(int i = 0;i < size;i++){
            if (s[i] == '5'){
                long long num = delete1(s, i + 1);
                if (num < min){
                    min = num;
                }
            }
            
        }
        return -min;
    }
}

int main(){
    long long N;
    cin >> N;
    cout << solution(N) << endl;
    return 0;
}