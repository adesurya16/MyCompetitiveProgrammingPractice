#include <bits/stdc++.h>
using namespace std;
const long modp = 1000000007;
long poweredMod(long a, long pow){
	if (pow == 0){
		return 1;
	}else if(pow == 1){
		return a % modp;
	}else if(pow % 2 == 0){
		long b = poweredMod(a, pow / 2) % modp;
		return (b*b) % modp;
	}else{
		long b = poweredMod(a, (pow - 1) / 2) % modp;
		return (((b*b) % modp) * (a % modp)) % modp;
	}
}
long permut1(long nr,long a){
	long res = 1;
	for(int i=a;i<nr;i++){
		res = (res * (i + 1)) % modp;
	}
	return res;
}

long permut2(long a){
	long tmp = permut1(a,0);
	long res = poweredMod(tmp,modp - 2);
	return res;
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		long n,m,max,min;
		cin >> n >> m;
		nr = n + m - 1;
		// smallest min(n,m - 1)
		if (n > m - 1){
			max = n;
			min = m - 1;
		}else{
			max = m - 1;
			min = n;
		}
		dr = min;
		long result1 = permut1(nr,max);
		long result2 = permut2(dr);
		cout << (result1 * result2) % modp << endl;
	}
	return 0;
}