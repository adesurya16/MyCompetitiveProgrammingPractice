#include <bits/stdc++.h>
using namespace std;

int main(){
    // factorisasi prima x
    int number;
    cin >> number;
    int result = 1;
    int top = number;
    int bot = 1;
    for(int i = 2;i*i <= number;i++){
        // cout << i << endl;
        if (number % i == 0){
            cout << i << endl;
            top *= (i - 1);
            bot *= i;
        }

        while (number % i == 0){
            number /= i;
        }

        if (number == 1) break;
    }
    if (number > 1){
        top *= (number - 1);
        bot *= number;
    }
    cout << top / bot << endl;

    // calculate x * n1()
    return 0;
}