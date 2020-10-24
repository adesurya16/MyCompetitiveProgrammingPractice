#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(int i=0;i < t;i++){
		int n,a,b,c;
		cin >> n;
		int max = 0;
		int min = 0;
		for(int j=0;j < n;j++){
			cin >> a >> b >> c;
			if (a >= b && a >= c){
				max += a;
				if(b >= c){
					min += c;
				}else{
					min += b;
				}
			}else if(b >= a && b >= c){
				max += b;
				if(a >= c){
					min += c;
				}else{
					min += a;
				}
			}else{
				max += c;
				if(a >= b){
					min += b;
				}else{
					min += a;
				}
			}
		}
		cout << min << " " << max << endl;
	}
	return 0;
}