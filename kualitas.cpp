#include <bits/stdc++.h>
using namespace std;

#define RESET(a,b) memset(a,b,sizeof(a))

int main(){
    int shirt[101];
    RESET(shirt, 0);
    
    int n;
    scanf("%d", &n);
    int idxMed = n;
    while(n--){
        int num;
        scanf("%d", &num);
        // cout << num << endl;
        shirt[num - 1]++;
        // cout << shirt[num - 1] << endl;
    }
    int idx = 0;
    float sum = 0;
    int shirtNum = 0;
    while(idx <= idxMed/2){
        while(shirt[shirtNum]==0){
            shirtNum++;
        }
        int num = shirtNum;
        if ((idxMed % 2 == 0 && (idx == idxMed/2 - 1 || idx == idxMed/2)) || (idxMed % 2 == 1 && idx == idxMed/2) ){
            // cout << "cal" << endl;
            sum = sum + num + 1; 
        }
        shirt[shirtNum]--;
        idx++;
    }
    if (idxMed % 2 == 0){
        printf("%.1f", sum/2);
    }else{
        printf("%.1f", sum);
    }    
    
    return 0;
}