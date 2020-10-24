#include <bits/stdc++.h>
using namespace std;
typedef struct Time{
    int start;
    int end;
} MyTime;
bool compare(MyTime t1,MyTime t2){
    return (t1.end < t2.end);
}
int main(){
    MyTime myTime[100];
    // vector<mytime> myTime;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> myTime[i].start >> myTime[i].end;
    }
        // cout << n << endl;
    
    sort(myTime, myTime + n, compare);
    int previousEnd = -1;
    for(int i=0;i<n;i++){
        if (myTime[i].start > previousEnd){
            cout << "[" << myTime[i].start << ", " << myTime[i].end << "]" << endl;
            previousEnd = myTime[i].end;
        }
    }
    return 0;
}