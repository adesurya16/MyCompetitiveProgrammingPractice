#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for ( int (i) = 0 ; (i) < (n) ; (i)++)

#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define sd(x) scanf("%lf", &x)
#define pd(x) printf("%.10lf\n", x)

class Mat{ // mat 2x2 or 2x1 only
    public:
        int x ,y;
        double tab[2][2]; // everything public not need setter getter
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
            newM.tab[i][j] = tab[i][j] + mat.tab[i][j];
        }
    }
    return newM;
}

Mat Mat::operator*(const Mat& mat){
    Mat newM(x, mat.y);
    FOR(i, x){
        FOR(j, mat.y){
            double res = 0;
            FOR(k, mat.x){
                res += (tab[i][k] * mat.tab[k][j]);  
            }
            newM.tab[i][j] = res;
        }
    }
    return newM;
}

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
    int n;
    double p;
    si(n);
    sd(p);
    Mat m(2, 2);
    m.tab[1][0] = p;
    m.tab[0][1] = p;
    m.tab[1][1] = 1 - p;
    m.tab[0][0] = 1 - p;

    Mat mBase(2, 1);
    mBase.tab[0][0] = 1 - p;
    mBase.tab[1][0] = p;
    
    if (n == 1){
        pd(1 - p);
    }else{
        Mat mRes = expoM(m, n - 1) * mBase;
        pd(mRes.tab[0][0]);
    }
    return 0;
}