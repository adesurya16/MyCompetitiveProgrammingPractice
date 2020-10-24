#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> vs;
    while(n--){    
        string s;
        cin >> s;
        vs.push_back(s);
        int newIdx = vs.size() - 1;
        for(int i = vs.size() - 1; i > 0;i--){
            // cout << "i" << endl;
            if (vs[i] < vs[i - 1]){
                newIdx = i - 1;
                swap(vs[i], vs[i-1]);
            }else break;
        }

        cout << newIdx + 1 << "\n";
    }
    return 0;
}