#include <bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for ( int (a) = (b); (a) < (c); (a)++)

// #define max 75
bool isHorisontal(int tab1[75][75], int tab2[75][75],int x,int y){
    FOR(i, 0, x){
        FOR(j, 0, y){
            if(tab1[i][j] != tab2[x - i - 1][j]){
                return false;
            }
        }
    }
    return true;
}

bool isVertikal(int tab1[75][75], int tab2[75][75],int x,int y){
    FOR(i, 0, x){
        FOR(j, 0, y){
            if(tab1[i][j] != tab2[i][y - j - 1]){
                return false;
            }
        }
    }
    return true;
}

bool isKananBawah(int tab1[75][75], int tab2[75][75],int x,int y){
    FOR(i, 0, x){
        FOR(j, 0, y){
            if(tab1[i][j] != tab2[j][i]){
                return false;
            }
        }
    }
    return true;
} 

bool isKiriBawah(int tab1[75][75], int tab2[75][75],int x,int y){
    FOR(i, 0, x){
        FOR(j, 0, y){
            if( tab1[i][j] != tab2[y - j - 1][x - i - 1] ){
                return false;
            }
        }
    }
    return true;
}

bool isIdentik(int tab1[75][75], int tab2[75][75],int x,int y){
    FOR(i, 0, x){
        FOR(j, 0, y){
            if(tab1[i][j] != tab2[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int tab1[75][75];
    int tab2[75][75];
    int x, y;
    cin >> x >> y;
    FOR(i, 0, x){
        FOR(j, 0, y){
            cin >> tab1[i][j];
        }
    }
    int a,b;
    cin >> a >> b;
    FOR(i, 0, a){
        FOR(j, 0, b){
            cin >> tab2[i][j];
        }
    }
    if ((x != a) || (y != b)){
        cout << "tidak identik" << endl;
    }else if (isVertikal(tab1,tab2,x,y)){
        cout << "vertikal" << endl;
    }else if(isHorisontal(tab1,tab2,x,y)){
        cout << "horisontal" << endl;
    }else if(isKiriBawah(tab1,tab2,x,y)){
        cout << "diagonal kiri bawah" << endl;
    }else if(isKananBawah(tab1,tab2,x,y)){
        cout << "diagonal kanan bawah" << endl;
    }else if(isIdentik(tab1,tab2,x,y)){
        cout << "identik" << endl;
    }else{
        cout << "tidak identik" << endl;
    }

    return 0;
}