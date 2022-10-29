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

void printPtr(ll val, int idx, int n)
{
    if (idx == n)
    {
        cout << val << endl;
    }
    else
        cout << val << " ";
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    string s;
    cin >> s;

    // calculate sum
    ll currentSum = 0;
    int left = 0, right = n - 1;
    vi arrVal(n);
    fo(i, n)
    {
        if (s[i] == 'L')
        {
            arrVal[i] = (i - left);
            currentSum += (ll)(i - left);
        }
        else
        {
            arrVal[i] = (right - i);
            currentSum += (ll)(right - i);
        }
    }
    // watch(currentSum);

    vector<char> expStr(n);
    ll maxSum = 0;
    int mid = left + (right - left) / 2;
    vi arrMaxVal(n);
    fo(i, n)
    {
        if (i <= mid)
        {
            expStr[i] = 'R';
        }
        else
        {
            expStr[i] = 'L';
        }
        if (expStr[i] == 'L')
        {
            arrMaxVal[i] = (i - left);
            maxSum += (ll)(i - left);
        }
        else
        {
            arrMaxVal[i] = (right - i);
            maxSum += (ll)(right - i);
        }
    }
    // watch(maxSum);
    int ptr = 0;
    fo(i, n)
    {
        if (left >= right)
        {
            break;
        }
        if (i % 2 == 0)
        {
            if (i > 0)
            {
                left++;
            }
            if (arrMaxVal[left] != arrVal[left])
            {
                currentSum -= arrVal[left];
                currentSum += arrMaxVal[left];
                ptr++;
                printPtr(currentSum, ptr, n);
                arrVal[left] = arrMaxVal[left];
            }
        }
        else
        {
            if (i > 1)
            {
                right--;
            }
            if (arrMaxVal[right] != arrVal[right])
            {
                currentSum -= arrVal[right];
                currentSum += arrMaxVal[right];
                ptr++;
                printPtr(currentSum, ptr, n);
                arrVal[left] = arrMaxVal[right];
            }
        }
    }

    fou(i, ptr + 1, n)
    {
        printPtr(maxSum, i, n);
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