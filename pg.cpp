#include <bits/stdc++.h>
using namespace std;
int main(){
    int MAX_M = 1000000000;
    int limit = floor(sqrt(MAX_M)) + 1;
    int n;
    scanf("%d", &n);

    // get prime
    vector<bool> v(limit + 1, true);
    // cout << "pass" << endl;
    vector<int> prime;
    // ignore 0 and 1
    for(int i = 2;i < limit + 1;i++){
        if (v[i]){
            prime.push_back(i);
            int itr = i + i;
            while(itr < limit + 1){
                v[itr] = false;
                itr += i;
            }
        }
    }   
    
    cout << prime.size() << endl;
    while(n--){
        int a,b;
        scanf("%d %d", &a, &b);
        vector<bool> v2(b - a + 1, true);
        // vector<int> prime2;
        for(int i = 0;i < b - a + 1;i++){
            int j = 0;
            while((i + a) % prime[j] > 0){
                j++;
                if (j == prime.size()) break;
            }
            if (j < prime.size()){
                v2[i] = false;
                // cout << i + a << " " << prime[j] << endl;
                int itr = i + prime[j];
                while(itr < b - a + 1){
                    v2[itr] = false;
                    itr += prime[j];
                }
            }
        }

        for(int i = 0;i < b - a + 1;i++){
            if(v2[i]){
                printf("%d\n", i + a);
            }
        }
    }

    return 0;
}