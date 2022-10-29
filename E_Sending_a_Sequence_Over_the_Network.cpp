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

void printDP(vb &d)
{
    int n = d.size();
    fo(i, n)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vi arr(n);
    fo(i, n) cin >> arr[i];
    vb dp(n + 1, 0);
    dp[0] = 1;
    fou(i, 1, n)
    {
        int val = arr[i - 1] + 1;
        if (i - val >= 0)
            dp[i] = dp[i] || dp[i - val];
    }
    // fo(i, n + 1) cout << dp[i] << " ";
    // cout << endl;
    printDP(dp);
    if (dp[n])
    {
        cout << "YES" << endl;
        return;
    }

    vb dp2(n + 1, 0);
    dp2[n] = 1;
    fod(i, n - 1, 0)
    {
        int val = arr[i] + 1;
        if (i + val <= n)
        {
            dp2[i] = dp2[i + val] || dp2[i];
        }
    }
    printDP(dp2);
    if (dp2[0])
    {
        cout << "YES" << endl;
        return;
    }
    fou(i, 0, n)
    {
        if (dp[i] && dp2[i])
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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