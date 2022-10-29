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

bool sortbyfirstasc(const pii &a,
                    const pii &b)
{
    if (a.f == b.f)
        return a.s < b.s;
    else
        return a.f < b.f;
}

bool sortbyfirstdesc(const pii &a,
                     const pii &b)
{
    if (a.f == b.f)
        return a.s < b.s;
    return a.f > b.f;
}

void printArr(vector<pii> &vp)
{
    fo(i, vp.size())
    {
        // watch(vp[i]);
        cout << i << " : " << vp[i].f << ", " << vp[i].s << endl;
    }
    cout << endl;
}

void solve(int cases = 1)
{
    // solve the problem here
    string s;
    cin >> s;

    int size = s.size();
    vector<pii> vp;
    fo(i, size)
    {
        // pair {value, index}
        vp.pb({(int)s[i] - (int)'a', i});
    }
    // printArr(vp);

    int leftVal = vp[0].f;
    int leftIdx = 0;
    int rightVal = vp[size - 1].f;
    int rightIdx = size - 1;
    // sort ascending if leftVal < rightVal
    if (leftVal < rightVal)
    {
        sort(vp.begin(), vp.end(), sortbyfirstasc);
    }
    else
    {
        sort(vp.begin(), vp.end(), sortbyfirstdesc);
    }

    // printArr(vp);
    // else descending

    int foundLeft, foundRight;
    fo(i, size)
    {
        if (vp[i].f == leftVal && vp[i].s == leftIdx)
        {
            foundLeft = i;
        }
        if (vp[i].f == rightVal && vp[i].s == rightIdx)
        {
            foundRight = i;
        }
    }

    vi res;
    int cost = 0;
    int preVal = vp[foundLeft].f;
    fo(i, size)
    {
        if (i >= foundLeft && i <= foundRight)
        {
            cost += abs(preVal - vp[i].f);
            preVal = vp[i].f;
            res.pb(vp[i].s + 1);
        }
    }

    cout << cost << " " << res.size() << endl;
    // print res
    fo(i, res.size())
    {
        if (i == 0)
        {
            cout << res[i];
        }
        else
            cout << " " << res[i];
    }
    cout << endl;
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