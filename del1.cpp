#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define watch(x) cout << (#x) << " : " << (x) << endl
 
int main(){
    string s1,s2;
    cin >> s1;
    cin >> s2;
    int i1 = 0;
    int i2 = 0;
    int del = 1;
    while(i1 < s1.size() && i2 < s2.size())
    {
        while(s1[i1] != s2[i2]){
            if (del > 0){
                del--;
                i1++;
                if (i1 == s1.size()){
                    cout << "Wah, tidak bisa :(" << endl;
                    return 0;
                }
            }else{
                cout << "Wah, tidak bisa :(" << endl;
                return 0;
            }
        }
        i1++;
        i2++;
    }    
    if (i1 == s1.size() && i2 == s2.size()){
        cout << "Tentu saja bisa!" << endl;
    }else cout << "Wah, tidak bisa :(" << endl;
    return 0;
}