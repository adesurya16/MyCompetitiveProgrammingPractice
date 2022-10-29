/* This Tempalte's only for competitive programming */
/* Created by Ade Surya Ramadhani ig/twitter : @adesuramadhan, github : adesurya16 */

#include <bits/stdc++.h> // warning not a standard may not found some platform
using namespace std;

#define endl "\n"
#define pb push_back
#define pob pop_back
#define mp make_pair
#define f first
#define s second
#define umap unordered_map
#define uset unordered_set
#define gc getchar_unlocked
#define ar array
#define PI 3.1415926535897932384626L
#define iMax INT_MAX
#define iMin INT_MIN

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define clr(x) memset(x, 0, sizeof(x))
#define cls(x) x.clear()
#define fo(i, n) for (int i = 0; i < (n); i++)
#define fou(i, a, b) for (int i = (a); i <= (b); i++)
#define fod(i, a, b) for (int i = (a); i >= (b); i--)
#define foreach(a, b) for (auto &a : b)
#define sqr(x) x *x
#define wc(x) while (x--)

#define watch(x) cerr << ">" << #x << " : " << x << endl

#define fastIO() \
    ;            \
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef vector<bool> vb;

const int MOD = 1e9 + 7; // 998244353

void getData(string &s, int &f, char &c)
{
    for (char i : s)
    {
        if (i == 'X')
            f++;
        else
            c = i;
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    string a, b;
    cin >> a >> b;
    int frontA = 0;
    int frontB = 0;
    char cA;
    char cB;
    map<char, int> val;
    val['L'] = 2;
    val['M'] = 1;
    val['S'] = 0;
    getData(a, frontA, cA);
    getData(b, frontB, cB);
    if (val[cA] > val[cB])
    {
        cout << ">" << endl;
    }
    else if (val[cA] < val[cB])
    {
        cout << "<" << endl;
    }
    else
    {
        if (frontA == frontB)
        {
            cout << "=" << endl;
        }
        else if (cA == 'L')
        {
            if (frontA > frontB)
            {
                cout << ">" << endl;
            }
            else
            {
                cout << "<" << endl;
            }
        }
        else
        {
            if (frontA < frontB)
            {
                cout << ">" << endl;
            }
            else
            {
                cout << "<" << endl;
            }
        }
    }
}

int main()
{
    fastIO();
    int cases = 1; // 1 or more cases
    cin >> cases;
    wc(cases)
    {
        solve();
    }
    return 0;
}