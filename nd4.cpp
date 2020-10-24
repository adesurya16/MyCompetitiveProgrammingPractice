/*
	Problem 4. I Am "The One" Number (30 point)
	1 <= N <= 1000

*/
#include <bits/stdc++.h>
using namespace std;
bool isTheOne(int num){
	// looping until 1 digit value
	while (num > 9){
		int tmp = num;
		int sum = 0;
		// find sum of digit
		while(tmp > 0){
			int x = tmp % 10;
			sum += (x * x);
			tmp = tmp / 10;
		}
		num = sum;
	}
	// the last might be one
	return (num == 1);
}
int main(){
	int n;
	cin >> n;
	int start = 100;
	while(n > 0){
		while(!isTheOne(start)){
			start++;
		}
		cout << start << " is The One Number" << endl;
		start++;
		n--;
	}
	
	return 0;
}