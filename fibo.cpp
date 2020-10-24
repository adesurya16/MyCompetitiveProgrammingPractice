#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define FOR(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define CASES(x) while(x--)

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define MOD 1000000007LL 

class Mat{ // mat 2x2 or 2x1 only
    public:
        int x ,y;
        LL tab[2][2]; // everything public not need setter getter
        Mat(int height, int width); // init matrix identity
        Mat(const Mat& mat); //ctor
        Mat operator=(const Mat& mat); // operator = overloading 
        Mat operator+(const Mat& mat); // operator + overloading
        Mat operator*(const Mat& mat); // operator * overloading
        void print();
};

Mat::Mat(int height, int width){
    x = height;
    y = width;
    tab[0][0] = 0;
    tab[1][0] = 0;
    tab[0][1] = 0;
    tab[1][1] = 0;
}

Mat::Mat(const Mat& mat){
    x = mat.x;
    y = mat.y;
    FOR(i,2){
        FOR(j,2){
            tab[i][j] = mat.tab[i][j];
        }
    }
}

Mat Mat::operator=(const Mat& mat){
    x = mat.x;
    y = mat.y;
    FOR(i, 2){
        FOR(j, 2){
            tab[i][j] = mat.tab[i][j];
        }
    }
    return *this;
}

Mat Mat::operator+(const Mat& mat){
    Mat newM(mat.x, mat.y);
    FOR(i, 2){
        FOR(j, 2){
            newM.tab[i][j] = (tab[i][j] + mat.tab[i][j]) % MOD;
        }
    }
    return newM;
}

Mat Mat::operator*(const Mat& mat){
    Mat newM(x, mat.y);
    FOR(i, x){
        FOR(j, mat.y){
            LL res = 0;
            FOR(k, mat.x){
                res = (res + (tab[i][k] * mat.tab[k][j] % MOD)) % MOD;  
            }
            newM.tab[i][j] = res;
        }
    }
    return newM;
}

// void Mat::print(){
//     cout << x << " " << y << endl;
//     FOR(i, x){
//         FOR(j, y){
//             cout << tab[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }

// LL expo(int x, int power){
//     if (power == 0) return 1;
//     LL res = 1;
//     LL pow = x;
//     while(power > 0){
//         if (power & 1){
//             res = ((res % MOD) * (pow % MOD)) % MOD;
//         }
//         // pll(res);
//         power >>= 1;
//         pow = ((pow % MOD) * (pow % MOD)) % MOD;
//     }
//     return res;
// }

Mat expoM(Mat m, int power){
    Mat mRes(2, 2);
    mRes.tab[0][0] = 1;
    mRes.tab[1][1] = 1;
    if (power == 0) {
        return mRes;
    }
    Mat mPow = m;
    // int loop = 0;
    // mPow.print();
    while(power > 0){
        // loop++;
        if (power & 1){
            mRes = mRes * mPow;
            // mRes.print();
        }
        power >>= 1;
        mPow = mPow * mPow;
    }
    // pi(loop);
    return mRes;
}

int main(){
    int x;
    si(x);
    // int x = 1;
    CASES(x){
        
        int n, a, b;
        si(a);
        si(b);
        si(n);
        Mat m(2, 2);
        m.tab[1][0] = 1;
        m.tab[0][1] = 1;
        m.tab[1][1] = 1;
        m.tab[0][0] = 0;
        Mat mBase(2, 1);
        mBase.tab[0][0] = a;
        mBase.tab[1][0] = b;
        if (n == 0){
            pi(a);
        }else if(n == 1){
            pi(b);
        }else{
            Mat mRes = expoM(m, n - 1) * mBase;
            pll(mRes.tab[1][0]);
        }
    }
    return 0;
}