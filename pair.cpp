#include <bits/stdc++.h>
using namespace std;

#define RESET(a,b) memset(a,b,sizeof(a))
// #define maxNumber 1000000

int main(){
    int t;
    // int maxNumber = 1000000;
    // int table[1000000];
    int maxNumber = 1000000;
    vector<int> table(maxNumber, 0);
    cin >> t;
    // cout << "tes" << endl;
    while(t--){
        int n;
        for(int i = 0;i < maxNumber;i++){
            table[i] = 0;
        }
        // RESET(table,0);
        // scanf("%d",&n);
        cin >> n;
        while(n--){
            int num;
            // scanf("%d",&num);
            cin >> num;
            table[num - 1]++;
        }
        long long sum = 0;
        for(int i = 0;i < maxNumber;i++){
            sum += (long long) ((long long)table[i]* (long long)(table[i] - 1));
        }
        cout << sum << endl;
    }
    return 0;
}