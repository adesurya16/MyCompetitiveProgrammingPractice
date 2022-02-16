// https://codeforces.com/group/yg7WhsFsAp/contest/355496/problem/P41
#include <bits/stdc++.h>
using namespace std;
int main(){
    int max = 300000 + 1;
    vector<bool> prime(max, true);
    prime[0] = false;
    prime[1] = false;
    // shieve of erathotenes
    for(int i = 2;i < max;i++){
        if(prime[i]){
            for(int j = i * 2; j < max; j+=i){
                prime[j] = false;
            }
        }
    }

    // create prefix sum frome prime vector
    vector<int> pre(max, 0);
    int sum = 0;
    for(int i = 0;i < max;i++){
        if (prime[i]) sum++;
        pre[i] = sum;
    }

    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        int left;
        if ((a - 1) >= 0){
            left = pre[a - 1];
        }else left = 0;
        int right = pre[b];
        cout << right - left << endl;
    }
    return 0;
}