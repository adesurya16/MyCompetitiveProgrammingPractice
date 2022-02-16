#include <bits/stdc++.h>
using namespace std;

long long delete1(string s, int dig){
    s.erase(dig - 1, 1);
    long long res = stoll(s);
    return res;
}

long long solution(long long N){
    
    if (N > 0){
        //positive case
        string s = to_string(N);
        int size = s.length();
        long long res = -1;
        // find first increase hill >5
        for(int i=0;i<size;i++){
            if(s[i] == '5'){
                if(i == size - 1){
                    // return delete1(s, size);
                    res = delete1(s, size);
                    break;
                }else if(s[i+ 1] > '5'){
                    res = delete1(s, i + 1);
                    break;
                }
            }
        }

        // find last decrease hill <=5
        if (res == -1){
            for(int i = size - 1; i>=0;i--){
                if(s[i] == '5'){
                    if(s[i + 1] < '5'){
                        res = delete1(s, i + 1);
                        break;
                    }
                }
            }
        }
        return res;
    
    }else{
        // negative case
        N = -N;
        string s = to_string(N);
        int size = s.length();
        long long res = -1;
        // find first decrase hill < 5
        for(int i=0;i<size;i++){
            if(s[i] == '5'){
                if(i == size - 1){
                    // return delete1(s, size);
                    res = delete1(s, size);
                    break;
                }else if(s[i+ 1] < '5'){
                    res = delete1(s, i + 1);
                    break;
                }
            }
        }

        // find last increase hill > 5
        if (res == -1){
            for(int i = size - 1; i>=0;i--){
                if(s[i] == '5'){
                    if(s[i + 1] > '5'){
                        res = delete1(s, i + 1);
                        break;
                    }
                }
            }
        }
        return -res;
    }
}

int main(){
    long long N;
    cin >> N;
    cout << solution(N) << endl;
    return 0;
}