#include <bits/stdc++.h>
using namespace std;

void permute(string s, int left, int right){
    if (left == right){
        cout << s << endl;
    }else{
        for(int i = left; i <= right;i++){
            swap(s[left],s[i]);
            permute(s, left + 1, right);
            swap(s[left],s[i]);
        }
    }
}

/* next_permutation complexity around O(n) but if u call continusly almost O(1) */

void permuteSTL(string 
    sort(s.begin(), s.end());
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));
}

int main(){
    string s;
    cin >> s;
    permute(s, 0, s.length() - 1);
    cout << endl;
    permuteSTL(s);
    return 0;
}