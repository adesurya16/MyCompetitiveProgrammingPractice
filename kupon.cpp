#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int kupon;
    cin >> n >> kupon;
    int min = INT_MAX;
    int kuponMin = INT_MAX;
    while(n--){
        int num;
        cin >> num;
        if(abs(num - kupon) < min || (abs(num - kupon) == min && num < kuponMin)){
            min = abs(num - kupon);
            kuponMin = num;
        }
    }
    cout << kuponMin << endl;
    return 0;
}