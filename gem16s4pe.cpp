#include <bits/stdc++.h>
using namespace std;
bool cek(int saklar,int l, int b){

}
int main(){
	int n;
	cin>>n;
	while(--n){
		cout << n << endl;
		int l,b;
		cin >> l >> b;
		// optimum lubang
		// saklar
		int saklar = 1;
		while(cek(saklar,l,b)){
			saklar++;
		}
	}
	return 0;
}