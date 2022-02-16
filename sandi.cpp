#include <bits/stdc++.h>
using namespace std;
int reverseOR(int resultK, int k){
    int res = 0;
    int idx = 0;
    while(resultK > 0 || k > 0){
        int bit1 = k & 1;
        int bit2 = resultK & 1;
        if(bit2 == 0 && bit1 == 1){
            res = -1;
            break;
        }else{
            res |= ((bit1 ^ bit2) << idx);
        }
        idx++;
        resultK >>= 1;
        k >>= 1;     
    }
    return res;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i=0;i < n;i++){
        int num;
        cin >> num;
        cout << reverseOR(num, k) << endl;
    }
    return 0;
}