#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define FOR(a,b,c) for (int (a) = (b); (a) < (c); (a)++)
#define FORD(a,b,c) for (int (a) = (b) - 1; (a) >= (c); (a)--)
#define max 100000
#define watch(x) cout << (#x) << " : " << (x) << endl

bool isPossibleBus(int xBus, int n, int tab[max]){
    int sum = 0;
    bool isPossible = true;
    FOR(i, 0, n){
        sum += tab[i];
        if (sum == xBus){
            sum = 0;
        }else if(sum > xBus){
            isPossible = false;
            break;
        }
    }
    if (sum > 0){
        isPossible = false;
    }
    return isPossible;
}

int main(){
    int n;
    cin >> n;
    int tab[max];
    long sum = 0;
    vi vector1, vector2;
    
    FOR(i, 0, n){
        cin >> tab[i];
        sum += tab[i];
    }
    
    FOR(j, 1, trunc(sqrt(sum)) + 1){
        if(sum % j == 0){
            if(isPossibleBus(j, n, tab)){
                vector1.push_back(j);
            }
            if(isPossibleBus(sum / j, n, tab) && (j != (sum / j))){
                vector2.push_back(sum / j);
            }
        }
    }
    
    if(vector1.size() > 0){
        cout << vector1[0];
        FOR(i, 1, vector1.size()){
            cout << " " << vector1[i];
        }
    }
    
    if(vector2.size() > 0){
        if(vector1.size() > 0){
            cout << " ";
        }
        cout << vector2[vector2.size() - 1];
        FORD(i, vector2.size() - 1, 0){
            cout << " " << vector2[i];
        }
    }
    cout << endl;
    return 0;
}