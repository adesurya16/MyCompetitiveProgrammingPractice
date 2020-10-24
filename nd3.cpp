/*
	Problem 3. Match Number
	1 <= N <= 1000
*/
#include <bits/stdc++.h>	
using namespace std;

// get inverse number
int getInverseNumber(int n){
	int num = 0;
	int tmp = 1;
	while (n > 0){
		int x = n % 10;
		// cout << x;
		n = n/10;
		num = num*10 + x;
		tmp = tmp*10;
	}
	return num;
}

bool isPrime(int prim){
	if (prim == 2){
		return true;
	}else if(prim == 1){
		return false;
	}else if(prim > 2){
		// check the divisor from 2 until trunc sqrt prim 
		for(int i=2;i<=trunc(sqrt(prim));i++){
			if(prim % i == 0){
				return false;				
			}
		}
		return true;
	}
}

int main(){
	int n;
	cin >> n;
	int start = 9;
	while(n > 0){
		start++;
		int num1 = start;
		int num2 = getInverseNumber(start);
		// check matching
		while(!(isPrime(num1) && isPrime(num2))){
			start++;
			num1 = start;
			num2 = getInverseNumber(start);
		}
		cout << num1 << " and " << num2 << " are Match" << endl;
		n--;
	}
	return 0;
}
