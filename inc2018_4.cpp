#include <bits/stdc++.h>
using namespace std;
int MAXN = 100000;
#define FOR(a, b, c) for ( int (a) = (b); (a) < (c); (a)++)
map<char,int> dic;

int main(){
    //init
    for(char i = 'a'; i <= 'z'; i++){
        // printf("%c",i);
        dic[i] = 0;
    }
    // printf("\n");

    char s1[MAXN + 1], s2[MAXN + 1];
    scanf("%s",s1);
    FOR(i, 0, strlen(s1)){
        dic[s1[i]]++;
    }
    scanf("%s",s2);
    FOR(i, 0, strlen(s2)){
        dic[s2[i]]--;
        if(dic[s2[i]] < 0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    // printf("%s %s\n",s1,s2);
    // printf("%d\n",strlen(s1));
    
    return 0;
}