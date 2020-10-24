#include <bits/stdc++.h>
using namespace std;
void multiply(int a[3][3], int b[3][3]){
	int res[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			res[i][j] = 0;
			for(int k=0;k<3;k++){
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			b[i][j] = res[i][j];
		}
	}
	return res[i][j];
} 

int power(int k, int a[3][3]){
	if(k == 1){

	}
}

int main(){
	
	return 0;
}