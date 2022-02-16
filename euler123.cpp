/* This Tempalte's only for competitive programming */
/* Created by Ade Surya Ramadhani @adesuramadhan/adesurya16 */

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
#define sqr(x) x *x // data type warning result

#define watch(x) cerr << ">" << #x << ":" << x << endl;

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

const int MOD = 1000000007; // 998244353

const int bound = 1000003;

vi primes;

void sieve();

ll mpow(ll base, int exp, ll modL);

void solve(int cases = 1)
{
    // solve the problem here
    ll exceedNum;
    cin >> exceedNum;
    int result = 0;

    // more optimal using binarysearch
    // cout << primes[0] << endl;
    // cout << primes.size() << endl;
    for (int i = 0; i < primes.size(); i++)
    {
        int exp = (i + 1);
        // watch(exp);
        ll mods = (ll)primes[i] * primes[i];
        // watch(mods);
        ll base1 = (ll)(primes[i] - 1);
        // watch(base1);
        ll base2 = (ll)(primes[i] + 1);
        // watch(base2);
        ll res1 = mpow((ll)(base1), exp, mods);
        // watch(res1);
        ll res2 = mpow((ll)(base2), exp, mods);
        // watch(res2);
        ll res = (res1 + res2) % mods;
        // watch(res);
        // cout << "res : " << (res1 + res2) % mods << endl;
        if (((res1 + res2) % mods) > exceedNum)
        {
            result = i + 1;
            break;
        }
        if (i + 1 == 5)
            break;
        // cout << endl;
    }
    cout << result << endl;
}

int main()
{
    // fastIO();
    sieve();
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}

// do sieve of erathotes
void sieve()
{
    // cout << "sieve" << endl;
    vb numbers = vb(bound + 1, 1);
    numbers[0] = 0;
    numbers[1] = 0;

    fou(i, 2, bound)
    {
        if (numbers[i])
        {
            primes.push_back(i);
            int compositeMark = i + i;
            for (int j = compositeMark; j <= bound; j += i)
            {
                numbers[j] = 0;
            }
        }
    }
}

ll mpow(ll base, int exp, ll modL)
{
    base %= modL;
    ll result = (ll)1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % modL;
        base = ((ll)base * base) % modL;
        exp >>= 1;
    }
    return result;
}