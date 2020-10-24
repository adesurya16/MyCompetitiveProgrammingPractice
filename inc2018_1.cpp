// tour de binus
#include <bits/stdc++.h>
using namespace std;
int find1(int x, string dir, int lim, int room[100]){
    int start = x - 1;
    int res = 0;
    while(start >= 0 && start < lim){
        res += room[start];
        if(dir.compare("left") == 0){
            start--;
        }else start++;
    }
    return res;
}
int find2(int x, string dir, int lim, int room[100]){
    int start = x - 1;
    int res = 0;
    while(start >= 0 && start < lim){
        // res += room[start];
        if (room[start] == 0){
            res++;
        }
        if(dir.compare("left") == 0){
            start--;
        }else start++;
    }
    return res;
}
int main(){
    int n;
    int room[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> room[i];
    }
    int budi,ayu;
    string sBudi,sAyu;
    cin >> ayu >> sAyu;
    // cout << ayu << " "<< sAyu << endl;
    cin >> budi >> sBudi;
    cout << find1(ayu, sAyu, n, room) << " " << find2(budi, sBudi, n, room) << endl;
    return 0;
}