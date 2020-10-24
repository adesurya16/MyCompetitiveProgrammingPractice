#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
// 2 pointer
#define FOR(a, c) for (int (a) = 0; (a) < (c); (a)++)
int main(){
    int n;
    si(n);
    vi vec(n);
    FOR(i, n){
        int num;
        si(num);
        vec[i] = num;
    }
    LL currentSum = 0;
    int left = 0;
    LL leftSum = vec[left];
    int right = n - 1;
    LL rightSum = vec[right];
    while(left < right){
        if (leftSum == rightSum){
            currentSum = leftSum;
            left++;
            right--;
            leftSum += vec[left];
            rightSum += vec[right];
        }else if(leftSum < rightSum){
            left++;
            leftSum += vec[left];
        }else{
            right--;
            rightSum += vec[right];
        }
    }
    pl(currentSum);
    return 0;
}