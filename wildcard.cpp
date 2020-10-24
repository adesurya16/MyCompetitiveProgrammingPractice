#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << (#x) << " : " << (x) << endl

int main(){
    string s1;
    cin >> s1;
    int size = s1.size();
    int n;
    size_t found = s1.find("*");
    string sLeft = s1.substr(0, found);
    string sRight = s1.substr(found + 1, size - found);
    cin >> n;
    while(n--){
        string s2;
        bool isLeft = false, isRight = false;
        cin >> s2;
        string ans = s2;
        if (found > 0){
            size_t f1 = s2.find(sLeft);
            if (f1 != string::npos && f1 == 0){
                isLeft = true;
                // cout << "yes1" << endl;
            }
        }else isLeft = true;

        if (found < size - 1 && isLeft){
            s2 = s2.substr(sLeft.size() + 1, s2.size() - sLeft.size());
            if(s2.size() >= sRight.size())
            {
                string dummy = s2.substr(s2.size() - sRight.size(), sRight.size());
                // cout << dummy << endl;
                size_t f1 = dummy.find(sRight);
                if (f1 != string::npos){
                    isRight = true;
                }
            }
        }else isRight = true;   
        if (isLeft && isRight) cout << ans <<"\n";
    }
    return 0;
}