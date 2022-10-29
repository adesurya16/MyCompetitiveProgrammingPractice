/* This Tempalte's only for competitive programming */
/* Created by Ade Surya Ramadhani @adesuramadhan/adesurya16 */

// https://codeforces.com/contest/1714/problem/A
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

#define watch(x) cerr << "> " << #x << " : " << x << endl

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

int hmToMinutes(int h, int m)
{
    return h * 60 + m;
}

vi minutesToHM(int minutes)
{
    vi res(2);
    res[0] = minutes / 60;
    res[1] = minutes % 60;
    return res;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n, H, M;
    cin >> n >> H >> M;
    int alarm = hmToMinutes(H, M);
    // watch(alarm);
    int minMinutes = iMax;
    wc(n)
    {
        int h, m;
        cin >> h >> m;
        int minutes = hmToMinutes(h, m) - alarm;
        if (minutes < 0)
        {
            minutes = hmToMinutes(24, 0) + minutes;
        }
        // watch(minutes);
        minMinutes = min(minMinutes, minutes);
    }

    vi res = minutesToHM(minMinutes);
    cout << res[0] << " " << res[1] << endl;
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