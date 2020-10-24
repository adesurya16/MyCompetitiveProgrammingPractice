#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int left = 0;
        while(left < s.length()){
            if(s[left] == '1'){
                break;
            }
            left++;
        }
        if (left == s.length() - 1){
            cout << 0 << endl;
        }else{
            int right = s.length() - 1;
            while(s[right] == '0'){
                right--;
            }
            int count = 0;
            for(int i = left;i<=right;i++){
                if (s[i] == '0') count++;
            }
            cout << count << endl;
        }
    }
    return 0;
}