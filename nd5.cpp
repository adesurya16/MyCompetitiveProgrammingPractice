/* 
	Problem 5. Biggest Z (30 Point) 
	1 <= ti <= 100000
	
	in the description we cant find case where Z cant be formed by ti, i have made an assumption program will make output as 
	"There no "'Z'" can be formed" if that case exist

	end of input is EOF (not a newline) i test this program using file input neither std input
*/

#include <bits/stdc++.h>
using namespace std;
// complexity is exponential we can optimaze using memoization
bool isSubsetSum(int table[100000],int sum, int idx){
	if (sum == 0){
		// possible
		return true;
	}else if(idx == 0 && sum != 0){
		// sum impossible happened in this part of case
		return false;
	}else if(table[idx - 1] > sum){
		// not counted
		return isSubsetSum(table, sum, idx - 1);
	}else{
		// call rekursif of 2 possiblity, where the table[n - 1] is included or excluded
		return isSubsetSum(table, sum - table[idx - 1], idx - 1) || isSubsetSum(table, sum, idx - 1);
	}
}

bool isPossibleFormed(int Z, int table[100000], int len){
	return isSubsetSum(table, Z, len);
}

int main(){
	int n;
	// max 100000
	int table[100000];
	int i =0;
	while((scanf("%d",&n)) != EOF){
		// cout << n;
		table[i] = n;
		i++;
	}
	int len = i;

	// DP problem??
	int Z = 0;
	while(isPossibleFormed(Z, table, len)){
		Z++;
	}
	cout << Z - 1 << endl;
	return 0;
}