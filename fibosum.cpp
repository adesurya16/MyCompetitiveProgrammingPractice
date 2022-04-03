// fibonacci sum FIBOSUM problem https://www.spoj.com/problems/FIBOSUM/
#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
typedef long long ll;
// #define watch(x) cerr << (#x) << " : " << (x) << endl

/*
    solution 1
 # formula (after breakdown the case) solution 1

 | F(n)     |  = | 2 0 -1 | ^ (n - 2)  * | F(2) = 2 |
 | F(n - 1) |    | 1 0 0 |               | F(1) = 1 |
 | F(n - 2) |    | 0 1 0 |               | F(0) = 0 |

  F(n, m) = F(m) - F(n)
*/

/*
    solution 2
 # Formula other version
 | F(n)     |  = | 1 1 1 | ^ (n - 1)  *  | F(1) = 1 |
 | f(n)     |    | 0 1 1 |               | f(1) = 1 |
 | f(n - 1) |    | 0 1 0 |               | f(0) = 0 |

*/

// create class of matrix
class Matrix
{
public:
    int x, y;
    vector<vector<ll>> m;
    Matrix(int h, int w);
    Matrix(int h, int w, vector<vector<ll>> &m);
    Matrix(const Matrix &matrix);
    Matrix operator=(const Matrix &matrix);
    Matrix operator+(const Matrix &matrix);
    Matrix operator*(const Matrix &matrix);
    // void print();
};

Matrix::Matrix(int h, int w)
{
    this->x = h;
    this->y = w;
    this->m = vector<vector<ll>>(this->x, vector<ll>(this->y, 0));
}

Matrix::Matrix(int h, int w, vector<vector<ll>> &m)
{
    this->x = h;
    this->y = w;
    this->m = vector<vector<ll>>(this->x, vector<ll>(this->y, 0));
    for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j < this->y; j++)
        {
            this->m[i][j] = m[i][j];
        }
    }
}

Matrix::Matrix(const Matrix &matrix)
{
    this->x = matrix.x;
    this->y = matrix.y;
    this->m = vector<vector<ll>>(this->x, vector<ll>(this->y, 0));
    for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j < this->y; j++)
        {
            this->m[i][j] = matrix.m[i][j];
        }
    }
}

Matrix Matrix::operator=(const Matrix &matrix)
{
    this->x = matrix.x;
    this->y = matrix.y;
    this->m = vector<vector<ll>>(this->x, vector<ll>(this->y, 0));
    for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j < this->y; j++)
        {
            this->m[i][j] = matrix.m[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &matrix)
{
    Matrix newM(matrix);
    for (int i = 0; i < newM.x; i++)
    {
        for (int j = 0; j < newM.y; j++)
        {
            newM.m[i][j] = (this->m[i][j] + matrix.m[i][j]) % MOD;
        }
    }
    return newM;
}

Matrix Matrix::operator*(const Matrix &matrix)
{
    Matrix newM(this->x, matrix.y);
    for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j < matrix.y; j++)
        {
            ll res = 0;
            for (int k = 0; k < matrix.x; k++)
            {
                res = (res + (this->m[i][k] * matrix.m[k][j]) % MOD) % MOD;
            }
            newM.m[i][j] = res;
        }
    }
    return newM;
}

// void Matrix::print()
// {
//     cerr << "matrix " << endl;
//     for (int i = 0; i < this->x; i++)
//     {
//         for (int j = 0; j < this->y; j++)
//         {
//             cerr << this->m[i][j] << " ";
//         }
//         cerr << endl;
//     }
// }

// create function fast exp using binary exponentiation (use MOD)
Matrix expoM(Matrix m, ll power)
{
    int size = m.x;
    Matrix mRes(size, size);
    for (int i = 0; i < size; i++)
    {
        mRes.m[i][i] = 1;
    }
    Matrix mPow = m;
    if (power == 0)
        return mRes;
    while (power > 0)
    {
        if (power & 1)
        {
            mRes = mRes * mPow;
        }
        power >>= 1;
        mPow = mPow * mPow;
    }
    return mRes;
}

int fiboSUM(ll n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
    {
        return 1;
    }
    vector<vector<ll>> mSumF = vector<vector<ll>>(3, vector<ll>(3, 0));
    // solution 2
    mSumF[0][1] = 1;
    mSumF[0][2] = 1;
    mSumF[0][0] = 1;
    mSumF[1][0] = 0;
    mSumF[1][1] = 1;
    mSumF[1][2] = 1;
    mSumF[2][0] = 0;
    mSumF[2][1] = 1;
    mSumF[2][2] = 0;

    Matrix sumF(3, 3, mSumF);

    vector<vector<ll>> mBasis = vector<vector<ll>>(3, vector<ll>(1, 0));
    mBasis[0][0] = 1;
    mBasis[1][0] = 1;
    mBasis[2][0] = 0;

    Matrix basis(3, 1, mBasis);

    Matrix res = expoM(sumF, n - 1) * basis;
    return res.m[0][0];
}

void solve(int cases = 1)
{
    // solve the problem here
    ll n, m;
    cin >> n >> m;
    // cant collect all possiblity because m,n <= 1x10^9

    // base case fibonacci : f(0) = 0, f(1) = 1

    // F(n, m) = sum( f(n), f(n + 1), ... , f(m))

    // hint : matrix exponentiation

    // subtract rule of the MOD??
    cout << (fiboSUM(m) % MOD - fiboSUM(n - 1) % MOD + MOD) % MOD << endl;
}

// void test()
// {
//     int n, m;
//     cin >> n >> m;
//     cout << fiboSUM(n) << endl;
//     cout << fiboSUM(m) << endl;
// }

int main()
{
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        // solve();
        solve();
    }
    return 0;
}