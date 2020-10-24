#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);
    vector< vector<int> > v;
    // cout << x << y << k << endl;
    for(int i = 0;i < x;i++){
        vector<int> d;
        for(int j = 0;j < y;j++){
            int num;
            scanf("%d", &num);
            // v[i][j] = num;
            d.push_back(num);
        }
        v.push_back(d);
    }
    int xRes = -1, yRes = -1;
    for(int j=0; j < y;j++){
        for(int i=0;i < x;i++){
            int res = 1;
            if(i - 1 >= 0){
                res *= v[i - 1][j];
            }
            if(i + 1 < x){
                res *= v[i + 1][j];
            }
            if(j - 1 >= 0){
                res *= v[i][j - 1];
            }
            if(j + 1 < y){
                res *= v[i][j + 1];
            }

            if (res == k && xRes == -1){
                // cout << res << endl;
                printf("%d %d\n",i + 1, j + 1);
                return 0;
            }
        }
    }
    printf("0 0\n");
    return 0;
}