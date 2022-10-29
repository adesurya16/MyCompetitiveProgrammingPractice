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

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<set<string>> vecOfSet(3);
    vi points(3, 0);
    fo(i, 3)
    {
        fo(j, n)
        {
            string s;
            cin >> s;
            vecOfSet[i].insert(s);
        }
    }
    fo(i, 3)
    {
        if (i == 0)
        {
            foreach (s, vecOfSet[0])
            {
                // watch(s);
                bool isFound1 = (vecOfSet[1].find(s) != vecOfSet[1].end());
                bool isFound2 = (vecOfSet[2].find(s) != vecOfSet[2].end());
                if (!isFound1 && !isFound2)
                {
                    points[0] += 3;
                }
                else if (isFound1 && !isFound2)
                {
                    points[0] += 1;
                    points[1] += 1;
                    vecOfSet[1].erase(s);
                }
                else if (!isFound1 && isFound2)
                {
                    points[0] += 1;
                    points[2] += 1;
                    vecOfSet[2].erase(s);
                }
                else
                {
                    vecOfSet[1].erase(s);
                    vecOfSet[2].erase(s);
                }
            }
            // clear 0
            vecOfSet[0].clear();
        }
        else if (i == 1)
        {
            foreach (s, vecOfSet[1])
            {
                // watch(s);
                if (vecOfSet[2].find(s) != vecOfSet[2].end())
                {
                    points[1] += 1;
                    points[2] += 1;
                    vecOfSet[2].erase(s);
                }
                else
                {
                    points[1] += 3;
                }
            }
            vecOfSet[1].clear();
        }
        else
        {
            foreach (s, vecOfSet[2])
            {
                // watch(s);
                points[2] += 3;
            }

            vecOfSet[2].clear();
        }
    }

    cout << points[0] << " " << points[1] << " " << points[2] << endl;
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