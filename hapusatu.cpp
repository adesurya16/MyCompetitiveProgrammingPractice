#include <bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    
    cin >> a;
    cin >> b;
    
    int pointer_a = 0;
    int pointer_b = 0;
    
    if(a.length() - b.length() == 1){
        while( pointer_a < a.length() ){
            if(a[pointer_a] == b[pointer_b]){
                pointer_a++;
                pointer_b++;
                // cout << a[pointer_a] << " " << b[pointer_b] << endl;
            }else if((a[pointer_a] != b[pointer_b]) && (pointer_a == pointer_b)){
                pointer_a++;
            }else{
                cout << "Wah, tidak bisa :(" << endl;
                return 0;
            }
        }
        cout << "Tentu saja bisa!" << endl;
    }else cout << "Wah, tidak bisa :(" << endl;  
    
    return 0;
}