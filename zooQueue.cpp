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

void build(vector<pii> &segment, vi &arr, int idx, int left, int right)
{
    if (left == right)
    {
        segment[idx] = {arr[left], arr[left]};
    }
    else
    {
        int mid = left + (right - left) / 2;
        build(segment, arr, 2 * idx + 1, left, mid);     // left
        build(segment, arr, 2 * idx + 2, mid + 1, right) // right
            segment[idx] = { max(segment[2 * idx + 1].f, segment[2 * idx + 2].f),
                             min(segment[2 * idx + 1].s, segment[2 * idx + 2].s) }
    }
}

bool query(vector<pii> &segment, int idx, int left, int right, int qLeft, int qRight, pii target)
{
    if (qLeft > right || qRight < left)
        return 0;
    else if (qLeft <= left && qRight >= right)
    {
        return
    }
    else
    {
        int mid =
    }
}

bool isZooQueue(vi arr)
{
    // build segment tree
    // node save (max, min) range[l..r]
    // int maxN = 2e6;
    int maxN = 100;
    vector<pii> segment(maxN * 2, {INT_MIN, INT_MAX});

    // build

    // find

    // maxLeft

    int size = arr.size();
    vector<int> maxLeft(size);
    int maxL = INT_MIN;
    fo(i, size)
    {
        maxL = min(maxL, arr[i]);
        maxLeft[i] = maxL;
    }
    fou(i, 1, size - 2)
    {
        maxL = maxLeft[i - 1];
        int val = arr[i];
        // query to find is value between them exist in other side (right)
        if (query())
        {
            return 0;
        }
    }
    return 1;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vi arr(n);
    fo(i, n)
    {
        cin >> arr[i];
    }
    if (isZooQueue(arr))
    {
        cout << "safe and sound" << endl;
    }
    else
        cout << "seven years of misfortune" << endl;
}

int main()
{
    fastIO();
    int cases = 1; // 1 or more cases
    // cin >> cases;
    wc(cases)
    {
        solve();
    }
    return 0;
}