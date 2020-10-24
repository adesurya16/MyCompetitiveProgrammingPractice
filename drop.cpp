#include <bits/stdc++.h>
using namespace std;
// floodfill
// A = 1
// B = 2
// C = 4
// ....
void floodfill(char dungeon[300][300], int &n,int i,int j,int x,int y){
	if ((i >= 0 && i < x) && (j >= 0 && j < y)){
		if(dungeon[i][j] != '#'){
			if(dungeon[i][j] == 'A'){
				n += 1;
			}else if(dungeon[i][j] == 'B'){
				n += 2;
			}else if(dungeon[i][j] == 'C'){
				n += 4;
			}else if(dungeon[i][j] == 'D'){
				n += 8;
			}else if(dungeon[i][j] == 'E'){
				n += 16;
			}
			dungeon[i][j] = '#';
			floodfill(dungeon, n, i + 1, j, x, y);
			floodfill(dungeon, n, i, j + 1, x, y);
			floodfill(dungeon, n, i - 1, j, x, y);
			floodfill(dungeon, n, i, j - 1, x, y);
		}
	}
}

int main(){
	int n, m, d;
	cin >> n >> m >> d;
	char dungeon[300][300];
	vector<int> vc;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>dungeon[i][j];
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout << dungeon[i][j];
	// 	}
	// 	cout << endl;
	// }
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dungeon[i][j] != '#'){
				int nDungeon = 0;
				floodfill(dungeon, nDungeon, i, j, n, m);
				vc.push_back(nDungeon);
			}
		}
	}
	sort(vc.begin(), vc.end(), greater<int>());
	// int l = 0;
	int sum = 0;
	// for(auto k = vc.begin(); k != vc.end(); ++k){
		// cout << *k << endl;
		// l++;
	// }
	for(int i=0;i<d;i++){
		cout << vc[i] << endl;
	}
	// vector<int> vc;
	return 0;
}