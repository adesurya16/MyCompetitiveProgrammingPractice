#include <bits/stdc++.h>
using namespace std;
int bSearch(vector<int> v, int num){
    int left = 0;
    int right = v.size() - 1;
    // cout << "in";
    while(left < right){
        
        int mid = left + (right - left)/2;
        // cout << left << " " << mid << " " << right << endl;
        
        if (v[mid] < num){
            left = mid + 1;
        }else right = mid;
        // if (left == right && v[left] == num) return left + 1;
    }
    if (left == right) return left + 1;
    return 0;
}

int main(){
    int n;
    vector<int> v;
    scanf("%d", &n);
    while(n--){
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    // sort(v.begin(), v.end()); //ascending
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d %d", &a, &b);
        int idxA = bSearch(v, a); // idx + 1
        int idxB = bSearch(v, b); // idx + 1, not found = 0
        printf("%d\n", idxB - idxA);
    }
    return 0;
}