// MEX problem
// split into 2 array A1, A2 where MEX(A1) == MEX(A2)
#include <bits/stdc++.h>
using namespace std;

int findMexIndex(vector<int> &arr)
{
    // complexity O(n) Time and O(n) Space
    // where n is the size of the array
    map<int, int> mapArrLeft, mapArrRight;

    // init mapArrRight
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mapArrRight[arr[i]]++;
    }

    // inisiasi awal mex akan bernilai 0 dan bertambah ketika ditemukan di hashmap kiri
    int mexLeft = 0;

    for (int i = 0; i < n - 1; i++)
    {
        mapArrLeft[arr[i]]++;
        mapArrRight[arr[i]]--;

        // while disini gak akan ngebuat O(N^2) karena ketika maxLeft bertambah nilai berarti sama aja kita udah kunjungi hashmap tersebut
        while (mapArrLeft.find(mexLeft) != mapArrLeft.end() && mapArrLeft[mexLeft] > 0)
            mexLeft++;
        // cout << i << " " << mexLeft << endl;

        // mexLeft kiri harus tidak ditemukan dihashmap kanan kalo tidak ditemukan berarti jawabanya karena nyari terkecil
        if (mapArrRight.find(mexLeft) == mapArrRight.end() || mapArrRight[mexLeft] == 0)
            return i;
    }
    return -1;
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        // non negative number
        cin >> arr[i];
    }
    cout << findMexIndex(arr) << endl;
}

int main()
{
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}