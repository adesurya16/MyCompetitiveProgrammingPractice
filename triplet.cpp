#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " : " << (x) << endl
int main(){
    unordered_map<int, int> mapping;
    int max = 1000000000;
    vector<int> vecint;
    int c, r;
    scanf("%d %d",&c, &r);
    while(c--){
        int val;
        scanf("%d", &val);
        vecint.push_back(val);
        if (mapping.find(val) != mapping.end()){
            mapping[val]++;
        }else mapping[val] = 1;
    }
    int sum = 0;
    if (r == 1){
        for(auto val : mapping){
            int num = val.first;
            sum += num * (num - 1) * (num - 2) / 6;
        }
    }else{
        for(int val : vecint){
            long long val2 = 0;
            val2 = val * r;
            if (val2 <= max){
                val2 = val2 * r;
                if (val2 <= max){
                    if(mapping.find(val * r) != mapping.end() && mapping.find(val * r * r) != mapping.end()){
                        sum += mapping[val * r] * mapping[val * r * r];
                    }
                }
            }
            mapping[val]--;
        }
    }
    printf("%d\n", sum);
    return 0;
}