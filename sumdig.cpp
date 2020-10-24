#include <bits/stdc++.h>
using namespace std;
#define cases(n) while(n--)

int main(){
    int n;
    cin >> n;
    cases(n){
        string s;
        cin >> s;
        int sum;
        cin >> sum;
        int start = 0;
        int min = 0;
        while (start < s.length() && sum > 1){
            if (s[start] <= sum - 1){
                sum -= s[start];
                start++;
            }else{
                sum = 1;
            }
        }

        string res = "";
        for(int i=s.length() - 1; i >= start;i--){
            char sChar = (char)((9 - ((int)s[i] - (int)'1' + 1)) + (int)'1' - 1);
            res = res + sChar;
        }
        cout << res << "\n";
    }
    return 0;
}