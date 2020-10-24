#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for ( int i = 0, _n = (n); i < _n; i++)
#define FOR(i, a, b) for ( int i = (a), _n = (b); i <= _n; i++)

const int maxN = 105;

int N;
int room[maxN];

int main(int argc, char * argv[]){
    scanf("%d", &N);
    FOR(i, 1, N){
        scanf("%d", &room[i]);
    } 
    return 0;
}