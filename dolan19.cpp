#include <bits/stdc++.h>
using namespace std;

// typedef vector<char> vc;
// typedef vector<vc> vvc;

#define FOR(a, b, c) for ( int (a) = (b); (a) < (c); (a)++)
// #define TC(t) while(t--)
#define endl '\n'
#define si(x) scanf("%d",&x)
#define watch(x) cout << (#x) << " : " << (x) << endl

int main(){
    int n; // people
    // ios_base::sync_with_stdio(0), cin.tie(NULL);
    int r ,c;
    si(n);
    si(r);
    si(c);
    int global_stat = 1; // 1 = balik, 2 = terpaksa, 3 = senang
    FOR(i, 0, r){
        string chairs;
        cin >> chairs;
        chairs = "O" + chairs + "O";
        // cout << chairs << endl; 
        // int prevIdx = 0;
        int len = 0;
        FOR(j, 1, c + 2){
            if (chairs[j] == 'L'){
                len++;
            }
            if (chairs[j] == 'P' || chairs[j] == 'O' || j == c + 1){
                if (len > 0){
                    int rightNB = j;
                    if (j == c - 1 && chairs[j] == 'L'){
                        rightNB = j + 1;
                    }
                    int leftNB = j - len - 1;
                    //proses
                    // watch(len);
                    // watch(leftNB);
                    // watch(rightNB);

                    // 3 cond
                    int stat;
                    if((len > n + 2) || ((len >= n) && chairs[leftNB] != 'P' && chairs[rightNB] != 'P') || ((len == n + 1) && (chairs[leftNB] != 'P' || chairs[rightNB] != 'P' ))){
                        stat = 3;   
                    }else if(len < n){
                        stat = 1;
                    }else {
                        stat = 2;
                    }
                    cout << stat << endl;
                    global_stat = max(global_stat, stat);
                    len = 0;
                }
            }
            
        }
    }
    // cout << global_stat << endl;
    if (global_stat == 1){
        cout << "BALIK AJA" << endl;
    }else if(global_stat == 2){
        cout << "TERPAKSA" << endl;
    }else{
        cout << "SENANG" << endl;
    }
    return 0;
}