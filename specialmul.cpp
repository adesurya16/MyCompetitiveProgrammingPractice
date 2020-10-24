#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef queue<LL> qLL;

#define RESET(a,b) memset(a,b,sizeof(a))
#define maxN 500

void initTable(int &n, LL number09, LL tableN[maxN]){
    for(int i=0;i < maxN;i++){
        if (tableN[i] == 0){
            if(number09 % (i + 1) == 0){
                n++;
                tableN[i] = number09;
            }
        }
        if(n == maxN) break;
    }
}

int main(){
    qLL QLL;
    LL tableN[maxN];
    RESET(tableN, 0);
    int n = 0;
    QLL.push(9);
    // int loop = 0;
    // int maxloop = pow(2, 18) - 1;
    // cout << maxloop << endl;
    while(n < maxN){
        LL number09 = QLL.front();
        // cout << number09 << endl;
        QLL.pop();
        QLL.push(number09*10);
        QLL.push(number09*10 + 9);
        initTable(n, number09, tableN);
        // cout << n << endl;
        // loop++;
    }
    int t;
    cin >> t;
    while(t--){
        int tn;
        cin >> tn;
        cout << tableN[tn - 1] << endl;
    }
    // cout << tableN[0] << endl;
    return 0;
}
