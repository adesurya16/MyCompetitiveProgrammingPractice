#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

#define ALLV(v) v.begin(),v.end()
#define SORTV(v) sort(ALLV(v))
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)
const int maxDiffer = 5;
int main(){
    int n
    si(n);
    vi vec(n);
    while(n--){
        int num;
        si(num);
        vec.push_back(num);
    }
    SORTV(vec);
    int left = 0;
    int right = vec.size() - 1;
    int maxTeam = 1;
    while (left < right){
        
    }
    return 0;
}