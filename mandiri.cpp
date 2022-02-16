#include <bits/stdc++.h>
using namespace std;
int findRight(vector<int> frek, int idxStart){ //acc
    idxStart++;
    while(idxStart < frek.size()){
        if(frek[idxStart] > 0){
           return idxStart; 
        }
        idxStart++;
    }
    return -1;
}

int findLeft(vector<int> frek, int idxStart){ //acc
    idxStart--;
    while(idxStart - 1 > 0){
        if(frek[idxStart] > 0){
            return idxStart;
        }
        idxStart--;
    }
    return -1;
}

int main(){
    vector<int> frek(26, 0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(char c : s){
        frek[(int)c - (int)'a']++;
    }
    // int start = 13;
    // int idx = findRight(frek, start);
    // cout << findRight(frek, start) << endl;
    // cout << findLeft(frek, start) << endl;
    
    for(int i=0;i < 26;i++){
        cout << (char)(i + (int)'a') << " : " << frek[i] << endl;
    }

    int pointer = findRight(frek, -1);
    // cout << pointer << endl;
    bool right = true;
    while(n > 0 ){
        cout << (char) (pointer + (int)'a');
        frek[pointer]--;
        n--;
        if(n > 0){
            if(right){
                pointer = findRight(frek, pointer);
                if (pointer != -1){
                    right = false;
                }else break; // impossible case
            }else{
                pointer = findLeft(frek, pointer);
                if (pointer != -1){
                    right = true;
                }else pointer = findRight(frek, pointer);
            }
        }
        
    }

    return 0;
}