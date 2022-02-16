#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(long long num){
    return num == (trunc(sqrt(num)) * trunc(sqrt(num)));
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        long long num;
        cin >> num;
        if (isPerfectSquare(num)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}