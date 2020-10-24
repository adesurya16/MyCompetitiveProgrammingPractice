#include <bits/stdc++.h>
using namespace std;
bool binarySearch(long long arr[],int l,int r,long long x){
	if(l <= r){
		int mid = l + (r - l)/2;

		if(arr[mid] == x){
			return true;
		}else if(arr[mid] < x){
			return binarySearch(arr, mid + 1, r, x);
		}else return binarySearch(arr, l, mid - 1, x);
	}
	return false;
}
int main(){
	long long prev = 1,next = 2;
	long long max = pow(10,10);
	int maxfib = 51;
	long long fib[maxfib];
	// cout << max << endl;
	int idx = 2;
	fib[0] = 1;
	fib[1] = prev;
	// store all fib < 10 ^ 10
	while(prev < max){
		fib[idx] = next;
		long long tmp = next;
		next = prev + next;
		prev = tmp;
		idx++;
	}
	// cout << idx << endl;
	// cout << endl;
	// for(int i=0;i < idx;i++){
	// 	cout << fib[i] << endl;
	// }

	int t;
	cin >> t;
	while(t--){
		long long x;
		cin >> x;
		if (binarySearch(fib, 0, idx - 1, x)){
			cout << "IsFibo" << endl;
		}else cout << "IsNotFibo" << endl; 	
	}
	
	// cout << binarySearch(fib, 0, idx, x) <<endl;
	// cout << prev << endl;
	// cout << next << endl;
	// cout << idx << endl;
	return 0;
}