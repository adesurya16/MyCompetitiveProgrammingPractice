#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	long md = 1000000007;
	while(t--){
		long n;
		cin >> n;
		cout << ((n % md) * (n % md)) % md << endl;
	}
	return 0;
}