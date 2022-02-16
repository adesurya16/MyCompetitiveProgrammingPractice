#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    bool beg = true;
    int power3 = 1;
    vector<int> vec;
    while(n > 0){
        int sisa = n % 3;
        if(sisa > 0){
            // if (!beg){
            //     printf(" ");
            // }else beg = false;
            
            if (sisa == 1){
                // printf("%d", power3);
                vec.push_back(power3);
            }else if(sisa == 2){
                // printf("%d %d", power3, power3);
                vec.push_back(power3);
                vec.push_back(power3);
            }
        }
        n = n / 3;
        power3 *= 3;
    }
    int len = vec.size();
    printf("%d\n", len);
    for(int i=0;i < len;i++){
        if(i > 0) printf(" ");
        printf("%d", vec[i]);
    }
    printf("\n");
    return 0;
}