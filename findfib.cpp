#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for ( int (a) = (b); (a) < (c); (a)++)

typedef long long LL;
// typedef struct m{
//     int matrix[2][2]
// } M;
// typedef struct m{
//     int matrixFib[2][1];
// } M;

int MOD = 1000000009;

void multipleMat1(int m1[2][2], int m2[2][2], int res[2][2]){
    // int res[2][2];
    FOR(i, 0, 2){
        FOR(j, 0, 2){
            res[i][j] = 0;
            FOR(k, 0, 2){
                res[i][j] = (res[i][j] + ((m1[i][k] * m2[k][j]) % MOD)) % MOD;
            }
        }
    }
    // return res;
}

void multipleMat2(int m1[2][2], int m2[2][1], int res[2][1]){
    // int res[2][1];
    FOR(i, 0, 2){
        FOR(j, 0, 1){
            res[i][j] = 0;
            FOR(k, 0, 2){
                res[i][j] = (res[i][j] + ((m1[i][k] * m2[k][j]) % MOD)) % MOD;
            }
        }
    }
    // return res;
}

void cpyMat1(int m[2][2], int res[2][2]){
    FOR(i, 0, 2){
        FOR(j, 0, 2){
            res[i][j] = m[i][j];
        }
    }
}

void cpyMat2(int m[2][1], int res[2][1]){
    FOR(i, 0, 2){
        FOR(j, 0, 1){
            res[i][j] = m[i][j];
        }
    }
}

void exponentialMat(int m[2][2], int power, int ret[2][2]){
    // power > 0
    if (power == 1){
        cpyMat1(m, ret);
        // return m;
    }else if(power % 2 == 0){
        int res[2][2];

        exponentialMat(m, power/2, res);
        multipleMat1(res, res, ret);
        // return multipleMat(res, res);
    }else{
        int res[2][2];
        exponentialMat(m, power/2, res);
        int res2[2][2];
        multipleMat1(res, res, res2);

        return multipleMat1(res2, m, ret);
    }
}

int main(){
    // matrix m;
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int f0,f1;
        int n;
        scanf("%d %d %d",&f0, &f1, &n);
        if(n == 0){
            printf("%d\n",f0);
        }else if(n == 1){
            printf("%d\n",f1);
        }else{
            int mFib[2][1]={f0, f1};
            int m[2][2]={{1, 1},{1, 0}};
            int mRes[2][1];
            int ret[2][2];
            exponentialMat(m, n - 1, ret);
            multipleMat2(ret, mFib, mRes);
            printf("%d\n", mRes[0][0]);
        }
    }
    return 0;
}