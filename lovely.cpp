#include <bits/stdc++.h>
using namespace std;
void solve(int cases = 1){
  // solve the problem here
  int p, q;
  cin >> p >> q;
  cout << ((p*p + q*q + 1) % 4 == 0 ? (p*p + q*q + 1)/4 : -1) << endl;
}

int main(){
  int cases = 1; // 1 or more cases
  // cin >> cases;
  while(cases--){
    solve();
  }
  return 0;
}