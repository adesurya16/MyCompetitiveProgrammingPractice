#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int gold;
        cin >> gold;
        int turn = 0;
        int getGold = 0;
        while(gold > 0){
            turn++;
            int tmp = 0;
            if(gold % 2 == 0){
                 tmp = gold/2;
            }else tmp = 1;
            if (turn % 2 == 1){
                // cout << tmp <<endl;
                getGold += tmp;
            }
            gold -= tmp;
        }
        cout << getGold << endl;
    }
    return 0;
}