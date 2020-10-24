#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
#define TC(t) while(t--)
#define endl "\n"
#define FOR(a, b, c) for ( int (a) = (b); (a) < (c); (a)++)
// #define push_back pb

bool compareString(string s1, string s2){
    return (s1.compare(s2) < 0);
}

int main(){
    int t;
    cin >> t;
    TC(t){
        int n;
        cin >> n;
        vs vec(n);
        FOR(i, 0, n){
            string s1, s2, s3, s4, s5, s6;
            cin >> s1; //2
            cin >> s2; //8
            cin >> s3; //4
            cin >> s4; //4
            cin >> s5; //4
            cin >> s6; //4
            vec[i] = s1 + " " +  s2 + " " + s3 + " " + s4 + " " + s5 + " " + s6;
        }
        sort(vec.begin(), vec.end(), compareString);
        int frek = 1;
        string prev = "";
        FOR(i, 0, n){
            if (prev != ""){
                if (prev.compare(vec[i]) != 0){
                    cout << vec[i] << " " << frek << endl;
                    frek = 1;
                }else{
                    frek++;
                }
            }
            prev = vec[i];
        }
        cout << prev << " " << frek << endl;
        cout << endl;
    }
    return 0;
}