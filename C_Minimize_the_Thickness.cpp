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

bool isKSegment(vi &arr, int expectedSum, int &high)
{
    // watch(expectedSum);
    int currSum = 0;
    int n = arr.size();
    int res = INT_MIN;
    int prev = 0;
    fo(i, n)
    {
        currSum += arr[i];
        if (currSum == expectedSum)
        {
            int len = i - prev + 1;
            res = max(res, len);
            prev = i + 1;
            currSum = 0;
        }
        else if (currSum > expectedSum)
        {
            return 0;
        }
    }
    if (currSum == 0)
    {
        high = res;
        return 1;
    }
    else
        return 0;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vi arr(n);
    int sum = 0;
    fo(i, n)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int res = INT_MAX;
    fou(i, 1, n)
    {
        int high;
        if (sum % i == 0 && isKSegment(arr, sum / i, high))
        {
            res = min(res, high);
        }
    }
    cout << res << endl;
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