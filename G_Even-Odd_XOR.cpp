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

/*
    3 -> {2 1 3}
    4 -> {2 1 3 0}
    5 -> {2 0 4 5 3}
    6 -> {4 1 2 12 3 8}
    7 -> (3) -> {16 17 18 19}
    8 -> (4) ->  {16 17 18 19}
    9 -> (5) -> {16 17 18 19}
    10 -> (6) -> {16 17 18 19}
*/

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vi res;
    if ((n - 3) % 4 == 0)
    {
        res = {2, 1, 3};
        n -= 3;
    }
    else if ((n - 4) % 4 == 0)
    {
        res = {2, 1, 3, 0};
        n -= 4;
    }
    else if ((n - 5) % 4 == 0)
    {
        res = {2, 0, 4, 5, 3};
        n -= 5;
    }
    else if ((n - 6) % 4 == 0)
    {
        res = {4, 1, 2, 12, 3, 8};
        n -= 6;
    }
    int start = 16;
    for (int i = 0; i < n; i += 4)
    {
        res.pb(start + i);
        res.pb(start + i + 1);
        res.pb(start + i + 2);
        res.pb(start + i + 3);
    }
    int len = res.size();
    fo(i, len)
    {
        if (i == len - 1)
            cout << res[i] << endl;
        else
            cout << res[i] << " ";
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