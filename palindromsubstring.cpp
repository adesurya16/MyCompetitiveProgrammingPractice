// palindrom substring problem using bruteforce O(N^3) or DP O(N^2)
#include <bits/stdc++.h>
using namespace std;
bool isPalindrom(string s1){
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    return s1 == s2;
}

string longestPalindrome(string s){
    int len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len));
    int max = INT_MIN;
    int idxMax = -1;
    for(int i = 0;i < len;i++){
        for(int j = 0; j < len - i;j++){
            int idxi = j;
            int idxj = j + i;
            if (idxi == idxj) {
                dp[idxi][idxj] = true;
            }else{
                if (idxi > idxj){
                    swap(idxi, idxj);
                }
                if (idxi + 1 > idxj - 1){
                    dp[idxi][idxj] = (s[idxi] == s[idxj]);
                }else{
                    dp[idxi][idxj] = (s[idxi] == s[idxj]) && dp[idxi+1][idxj-1];
                }
            }
            if (dp[idxi][idxj] && (idxj - idxi + 1) > max){
                max = idxj - idxi + 1;
                idxMax = idxi;
            }
        }
    }
    return s.substr(idxMax, max);
}

int main(){
    string s1;
    cin >> s1;

    // bruteforce
    int len = s1.length();
    int max = INT_MIN;
    int maxIdx = -1;
    for(int i = 0; i < len; i++){
        for(int j = i;j < len;j++){
            if ((j - i + 1) > max && isPalindrom(s1.substr(i, j - i + 1))){
                max = j - i + 1;
                maxIdx = i;
            }
        }
    }

    // bruteforce vs dp
    cout << s1.substr(maxIdx, max) << endl;
    cout << longestPalindrome(s1) << endl;
    return 0;
}