#include <bits/stdc++.h>
using namespace std;
int calculate(int j, int k, int area, int areaPotong){
    int price = 0;
    while (areaPotong > 0){
        int potong2 = area - (area/2);
        int pricePotong1 = potong2*j;
        // int pricePotong2 = k;
        if (k < pricePotong1 && potong2 <= areaPotong){
            price += k;
            area -= potong2;
            areaPotong -= potong2;
        }else{
            price += (areaPotong * j);
            areaPotong = 0;
            area -= areaPotong;
        }
    }
    return price;
}

int main(){
    int n, a, d;
    cin >> n >> a >> d;
    int idxMin = -1;
    int minPrice = INT_MAX;
    while(n--){
        int i, j, k;
        cin >> i >> j >> k;
        // calculate Minimum
        int price = calculate(j, k, a, d);
        if (price < minPrice){
            idxMin = i;
            minPrice = price;
        }else if (price == minPrice && i < idxMin){
            idxMin = i;
        }        
    }
    cout << idxMin << " " << minPrice << endl;
    return 0;
}