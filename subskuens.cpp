// OSP 2018
// Essay
#include <bits/stdc++.h>
using namespace std;
int maxVec(vector<int> v){
    int maxInt = INT_MIN;
    for(int i=0;i<10;i++){
        maxInt = max(v[i], maxInt);
    }
    return maxInt;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    vector<int> vec(n);
    vector<int> frekR(10, 0);
    
    while(n--){
        int num;
        cin >> num;
        vec.push_back(num);
        frekR[num - 1]++;
    }

    vector<int> frekL(10, 0);
    int maxGlobal = maxVec(frekR);
    for(int i=0;i<n;i++){
        frekL[vec[i]]++;
        frekR[vec[i]]--;
        maxGlobal = max(maxGlobal, maxVec(frekL) + maxVec(frekR));
    }
    cout << maxGlobal << "\n";
    return 0;
}