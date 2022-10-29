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

// void printArr(vvi &arr)
// {
//     int x = arr.size(), y = arr[0].size();
//     fo(i, x)
//     {
//         fo(j, y)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// } 

int query2DSum(pii topLeftPoint, pii bottomRightPoint, vvll &prefixFarm)
{
    // point {x, y}
    ll prefixSum = prefixFarm[bottomRightPoint.f + 1][bottomRightPoint.s + 1];
    ll topPrefixSum = prefixFarm[topLeftPoint.f][bottomRightPoint.s + 1];
    ll leftPrefixSum = prefixFarm[bottomRightPoint.f + 1][topLeftPoint.s];
    ll topLeftPrefixSum = prefixFarm[topLeftPoint.f][topLeftPoint.s];
    return prefixSum - (topPrefixSum + leftPrefixSum - topLeftPrefixSum);
}

pii binarySearch(pii lowPoint, pii highPoint, vvll &prefixFarm, int target)
{

    // cout << "low : " << lowPoint.f << " " << lowPoint.s << endl;
    // cout << "high : " << highPoint.f << " " << highPoint.s << endl;
    // cout << endl;

    pii qBottomRightPoint = highPoint;

    pii res = {-1, -1};

    // if (query2DSum(lowPoint, highPoint, prefixFarm) < target)
    // {
    //     return res;
    // }
    // low means topLeft, high means bottom right

    // requirement high x - low x == high y
    // >= k
    // (minValue, point), (maxValue, point)
    // find latest true from descending

    // point to point 1 diagonal
    while (lowPoint.f <= highPoint.f && lowPoint.s <= highPoint.s)
    {
        pii mid = {lowPoint.f + (highPoint.f - lowPoint.f) / 2, lowPoint.s + (highPoint.s - lowPoint.s) / 2};
        // cout << lowPoint.f << " , " << lowPoint.s << endl;
        // cout << mid.f << " , " << mid.s << endl;
        // cout << highPoint.f << " , " << highPoint.s << endl;
        ll qSum = query2DSum(mid, qBottomRightPoint, prefixFarm);
        // cout << "qSum : " << qSum << endl;
        // cout << endl;

        if (qSum >= (ll)target)
        {
            res = mid;
            mid.f++;
            mid.s++;
            lowPoint = mid;
        }
        else
        {
            mid.f--;
            mid.s--;
            highPoint = mid;
        }
    }
    return res;
}

int countMushroomFarm(vvi &farm, int k)
{
    int x = farm.size(), y = farm[0].size();
    vvll prefixFarm(x + 1, vll(y + 1));

    // init prefix farm
    fo(i, x + 1)
    {
        fo(j, y + 1)
        {
            if (i == 0 || j == 0)
            {
                prefixFarm[i][j] = 0;
            }
            else
            {
                prefixFarm[i][j] = prefixFarm[i - 1][j] + prefixFarm[i][j - 1] - prefixFarm[i - 1][j - 1] + (ll)farm[i - 1][j - 1];
            }
        }
    }

    // prefix farm print

    // cout << "print prefix farm" << endl;
    // printArr(prefixFarm);

    // cout << query2DSum({1, 1}, {3, 3}, prefixFarm) << endl;

    // cout << query2DSum({2, 2}, {3, 3}, prefixFarm) << endl;

    // loop by farm
    int sumEqualOrMoreK = 0;
    fo(i, x)
    {
        fo(j, y)
        {
            // find high and low point
            pii high = {i, j};
            pii low = {i - min(i, j), j - min(i, j)};
            pii lastFound = binarySearch(low, high, prefixFarm, k);

            if (lastFound.f != -1 && lastFound.s != -1)
            {
                // calucalate current count from high and lastFound point
                int count = lastFound.f - low.f + 1;
                sumEqualOrMoreK += count;
                // add to summain
            }
        }
    }
    // pii high = {2, 2};
    // pii low = {0, 0};
    // pii lastFound = binarySearch(low, high, farm, prefixFarm, k);
    // cout << lastFound.f << " " << lastFound.s << endl;
    // cout << lastFound.f - low.f + 1 << endl;

    return sumEqualOrMoreK;
}

void solve(int cases = 1)
{
    // solve the problem here
    // mushroomfarm problem
    // NOI Selection Test 2017 simulation
    // codebreaker.xyz

    // x,y <= 2000 , 1 ,1 <= k <= 10^9, every sel matrix M, 1 <= M <= 300
    int x, y, k;
    cin >> x >> y >> k;
    vvi farm(x, vi(y));
    fo(i, x)
    {
        fo(j, y)
        {
            cin >> farm[i][j];
        }
    }

    // cout << "print farm" << endl;
    // printArr(farm);
    // cout << endl;

    // what should i need (2D query matrix problem)

    // binary search each diagonal possibility

    // should be O(n^2logn)

    cout << countMushroomFarm(farm, k) << endl;
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