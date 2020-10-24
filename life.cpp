#include <bits/stdc++.h>
using namespace std;
int main(){
    int inp;
    int stop = 0;
    while (cin>>inp){
        if (inp == 42) stop = 1;
        if (!stop){
            printf("%d\n", inp);
            
        }
    }
    return 0;
}