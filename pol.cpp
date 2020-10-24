#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	
	for(int i=0;i < n;i++){
		string c;
		map<char,int> frek;
		for(int j=0;j<26;j++){
			frek[(char)(j + 97)] = 0;
		}
		cin >> c;
		for(int j=0;j<c.length();j++){
			// input always a-z
			frek[c[j]]++;
			// cout << frek[c] << endl;
		}
		int sum = 0;
		int remaining = 0;
		for(int j=0;j<26;j++){
			sum += (frek[(char)(j + 97)]/2);
			remaining += (frek[(char)(j + 97)] % 2);
		}
		if (remaining > 0){
			cout << sum + 1 << endl;
		}else cout << sum << endl;
		// for(int j=0;j<26;j++){
			
		// 	cout << (char)(j + 97) << " : " << frek[(char)(j + 97)] << endl;
		// }
	}
}