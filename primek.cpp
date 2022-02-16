#include <bits/stdc++.h>
using namespace std;
int main(){
    int max = 989999 + 1; // last prime K = 77777
    vector<bool> num = vector<bool>(max, true); // true = prime
    vector<int> primeK;
    for(int i = 2;i < max;i++){
        if(num[i]){
            primeK.push_back(i);
            int start = i + i;
            while(start < max){
                num[start] = false;
                start += i;
            }
            // if (primeK.size() == 77777){
            //     cout << i << endl;
            //     break;
            // }
        }
        
    }
    // cout << primeK.size() << endl;
    // for(int prime : primeK){
    //     cout << prime << " ";
    // }
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        cout << primeK[k - 1] << endl;
    }
    return 0;
}