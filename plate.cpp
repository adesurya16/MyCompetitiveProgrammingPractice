#include <bits/stdc++.h>
using namespace std;
#define FOR(a, b, c) for ( int (a) = (b); (a) < (c); (a)++)
void calculate(int &evens, int &odds, int B){
    int A = 0;
    int a = A, b = B;
    int sum = 0;
    int odd = 0;
    while(b > 0){
        sum = b - a + 1;
        odd += (sum / 2);
        
        if (a % 2 == 1 && b % 2 == 1){
            odd++;
        }
        // cout << odd << endl;
        a = a/10;
        b = b/10;
        
    }
    int even = (B - A + 1) - odd;
    evens = even;
    odds = odd;
}
int main(){
    int A,B;
    cin >> A >> B;
    int oddA, evenA;
    calculate(evenA, oddA, A);
    int oddB,evenB;
    calculate(evenB, oddB, B);
    cout << oddB - oddA + 1 << " " << evenB - evenA << endl;
    return 0;
}
