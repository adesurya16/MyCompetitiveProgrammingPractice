#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

#define FOR(i , a, n) for(int (i) = (a); (i) < (n); (i)++)
#define CASES(n) while(n--)
#define watch(x) cout << (#x) << " : " << (x) << endl
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)

void test_cases(){
    int size;
    si(size);
    vi nums(size);
    FOR(i, 0, size){
        int num;
        si(num);
        nums[i] = num; 
    }
    // build segment tree

    int qSize;
    si(qSize);
    FOR(i, 0, qSize){
        int q1, q2;
        si(q1);
        si(q2);
        int res = compute(q1, q2);
    }
}

int main(){
    // segment tree
    // store and operator every pieces
    int n;
    si(n);
    CASES(n){
        test_cases();
    }
    return 0;
}