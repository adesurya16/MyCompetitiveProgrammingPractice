#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL);
	int n;
	cin >> n;
	while(n--){
		long long x;
		cin >> x;
        if(x == 1) cout << "NO" << endl;
        else{
            if (x == trunc(sqrt(x)) * trunc(sqrt(x))) cout << "YES" << endl;
		    else cout << "NO" << endl;
        }
	}
	// your code goes here
	return 0;
}