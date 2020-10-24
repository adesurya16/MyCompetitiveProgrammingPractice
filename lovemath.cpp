#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for ( int (a) = (b); (a) < (c); (a)++)

// typedef vector<int> vDigit
// #define vector<int> vDigit

vector<int> number2Vec(string s){
    vector<int> num(10, 0);
    for(char c : s){
        int val = c - '0';
        num[val]++;
    }
    return num;
}

bool isDivBy8(vector<int> v1, vector<int> v2){ // v2 : multiple8
    int vsize = v1.size();
    FOR(i, 0, vsize){
        if (v1[i] < v2[i]) return false;
    }
    return true;
}


int main(){
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    //store all divisible 8 (1 - 1000)
    vector<vector<int>> vDigitList;
    // vector<string> vS;
    int i = 0;
    while(i < 1000){
        string s = to_string(i);
        if (i < 10){
            s = "00" + s;
        }else if (i < 100){
            s = "0" + s;
        }
        vDigitList.push_back(number2Vec(s));
        // vS.push_back(s);
        // cout << s << endl;
        i += 8;
    }
    // vDigit v;
    int n;
    scanf("%d",&n);
    while(n--){
        string s;
        cin >> s;
        if (s.length() < 2){
            s = "00" + s;
        }else if (s.length() < 3){
            s ="0" + s;
        }
        // cout << s << endl;
        // 110 digit max
        vector<int> vs = number2Vec(s);
        bool isFound = false;
        // int ii = 0;
        for(vector<int> vDig : vDigitList){
            if (isDivBy8(vs, vDig)){
                isFound = true;
                // cout << vS[ii] << endl;
                // ii++;
                break;
            }
        }
        if (isFound) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}