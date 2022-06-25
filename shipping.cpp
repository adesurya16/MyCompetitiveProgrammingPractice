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
#define sqr(x) x *x

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

vector<int> shipping(int N, vector<int> h)
{
    // Your code starts here.
    // shipping between cities problem
    // N is the number of cities
    // h[i] is price city i
    // return the minimum price

    vector<int> minPrice(N);
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            minPrice[i] = h[i];
        }
        else
        {
            minPrice[i] = min(h[i], minPrice[i - 1] + 1);
        }
    }
    // vector<int> minPrice2(N, 0);
    // for (int i = N - 1; i >= 0; i--)
    // {
    //     if (i == N - 1)
    //     {
    //         minPrice2[i] = h[i];
    //     }
    //     else
    //     {
    //         minPrice2[i] = min(h[i], minPrice2[i + 1] + 1);
    //     }
    // }
    // vector<int> res(N, 0);
    // for (int i = 0; i < N; i++)
    // {
    //     res[i] = min(minPrice[i], minPrice2[i]);
    // }

    vector<int> res(N);
    for (int i = N - 1; i >= 0; i--)
    {
        if (i == N - 1)
        {
            res[i] = minPrice[i];
        }
        else
        {
            res[i] = min(minPrice[i], res[i + 1] + 1);
        }
    }
    return res;
}

void solve(int cases = 1)
{
    // solve the problem here
    int N;
    cin >> N;
    vector<int> h;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        h.push_back(x);
    }
    vector<int> ans = shipping(N, h);
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
}

int main()
{
    fastIO();
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}