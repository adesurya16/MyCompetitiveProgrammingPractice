#include <bits/stdc++.h>
using namespace std;
int main(){
    // push top pop size empty 
    priority_queue<int> pQ;
    pQ.push(7);
    pQ.push(6);
    pQ.push(1);
    pQ.push(1);
    pQ.push(4);
    pQ.push(5);
    while (pQ.size() > 1){
        int q = pQ.top();
        pQ.pop();
        q = q - pQ.top();
        pQ.pop();
        if (q > 0){
            pQ.push(q);
        }
    } 
    if (pQ.size() > 0){
        cout << pQ.top() << endl;
    }else cout << 0 << endl;
    return 0;
}