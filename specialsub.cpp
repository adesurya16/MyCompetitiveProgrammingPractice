#include <bits/stdc++.h>
using namespace std;
int alphaMax(vector<int> alpha){
    int maxim = INT_MIN;
    for(int i : alpha){
        
        maxim = max(maxim, i); 
    }
    return maxim;
}
int main(){
    vector<int> alpha(25, 0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for(int i=0;i<k;i++){
        alpha[s[i] - (int)'A']++;
    }
    int maxim = alphaMax(alpha);
    for(int i=k;i<n;i++){
        alpha[s[i] - (int)'A']++;
        alpha[s[i - k]]--;
        maxim = max(maxim, alphaMax(alpha));
    }
    cout << k - maxim << endl;
    return 0;
}