#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> A,vector<string> D){
    vector<int> sumOfPaymentsCounted(12, 0);
    int total = 0;
    vector<int> sumOfPaymentsMoney(12, 0);
    
    for(int i=0;i < A.size();i++){
        // current month?
        total += A[i];
        string date = D[i];
        int month = ((int)date[5] - (int)'0') * 10 + ((int)date[6] - (int)'0');
        // cout << month << endl;
        // only payments counted
        if(A[i] < 0){
            sumOfPaymentsCounted[month - 1]++;
            sumOfPaymentsMoney[month - 1] = sumOfPaymentsMoney[month - 1] + A[i]; 
        }
        
    }

    // calculate total 12 month in 2020
    for(int i = 0;i < 12; i++){
        // cout << sumOfPaymentsCounted[i] << " " << sumOfPaymentsMoney[i] << endl;
        if (!(sumOfPaymentsCounted[i] >= 3 && -sumOfPaymentsMoney[i] >= 100)){
            total -= 5;
        }
    }  
    return total;
} 
int main(){
    int n;
    cin >> n;
    vector<int> A;
    for(int j=0;j<n;j++){
        int i;
        cin >> i;
        A.push_back(i);
    }
    vector<string> D;
    for(int j=0;j<n;j++){
        string s;
        cin >> s;
        // cout << s << endl;
        D.push_back(s);
    }
    cout << solution(A, D) << endl;
    return 0;
}