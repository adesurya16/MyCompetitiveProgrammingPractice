#include <bits/stdc++.h>
using namespace std;
bool isHappy(int n) {
        while(n > 9){
            int num = n;
            int sum = 0;
            while(num > 0){
                int remind = num % 10;
                sum += (remind*remind);
                num = num / 10;
            }
            n = sum;
            cout << n << endl;
        }
        return (n == 1);
    }
int main(){
    cout << isHappy(19) << endl;
    return 0;
}