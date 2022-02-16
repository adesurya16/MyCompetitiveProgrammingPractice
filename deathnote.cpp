#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int save = 0; // remainder of every writing name action in a page
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        int page = 0;
        // cout << "save : " << save << endl;
        
        if (save > 0){
            if((m - save) <= num){
                page++;
                num -= (m - save);
                save = 0;
            }
        }
        page += (num / m);
        save += (num % m);
        cout << page << endl;
    }
    return 0;
}