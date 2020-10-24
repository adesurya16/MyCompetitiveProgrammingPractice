#include <bits/stdc++.h>
using namespace std;
// typedef tuple<int, int> tp;
map<pair<int,int>,int> mapping;
// memoization
int palindrom(int l, int r, string s){
	if(mapping.find(make_pair(l,r)) != mapping.end()){
		return mapping[make_pair(l,r)];
	}
	if(l == r){
		return 1;
	}else if(l > r){
		return 0;
	}else if(s[l] != s[r]){
		return max(palindrom(l+1, r, s), palindrom(l, r-1, s));
	}else{
		int sv = 2 + palindrom(l+1, r-1, s);
		mapping[make_pair(l,r)] = sv;
		return sv;
	}
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		mapping.clear();
		cout << palindrom(0, s.length() - 1, s) << endl;
	}
	return 0;
}