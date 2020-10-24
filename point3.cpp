#include <bits/stdc++.h>
using namespace std;
#define FOR(a, b, c) for(int (a) = (b); (a) < (c); (a)++)

int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    while(n--){
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    int sum = 0;
    for(int i : v){
        int x;
        scanf("%d", &x);
        if (i > x){
            sum += 3;
        }else if(i == x){
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}