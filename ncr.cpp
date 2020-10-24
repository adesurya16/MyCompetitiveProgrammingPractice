#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define FOR(a, b, c) for ( int (a) = (b); (a) < (c); (a)++)
#define CASE(n) while(n--)

int mod = 1000000000;
int maxint = 1000;

int main(){
    vvi vec;
    FOR(i, 1, maxint){
        // cout << i << endl;
        vi vecdummy;
        if (i == 1){
            // cout << "test" <<  endl;
            vecdummy.push_back(1);
            vecdummy.push_back(1);
        }else{
            vi v = vec.back();
            FOR(j, 0, v.size() + 1){
                if (j == 0 || j == v.size()){
                    vecdummy.push_back(1);
                }else{
                    vecdummy.push_back((v[j - 1] + v[j]) % mod);
                }
            }
        }
        vec.push_back(vecdummy);
    }
    int n;
    scanf("%d", &n);
    CASE(n){
        int n;
        scanf("%d", &n);
        vi v = vec[n - 1];
        int size = v.size();
        FOR(i, 0, size){
            if (i == 0){
                printf("%d", v[i]);
            }else printf(" %d", v[i]);
        }
        printf("\n");
    }
    return 0;
}