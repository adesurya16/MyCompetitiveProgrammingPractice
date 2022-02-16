#include <bits/stdc++.h>
using namespace std;
// 
typedef vector<int> vi;

void quicksortHoare(vi arr, int left, int right){
    if (left < right){
        int pivot = arr[left];
        int pLeft = left;
        int pRight = right;
        while(pLeft <= pRight){
            while (pLeft <= pRight && arr[pLeft] <= pivot){
                pLeft++;    
            }
            while (pLeft <= pRight && arr[pRight] > pivot){
                pRight--;
            }
            if (pLeft < pRight){
                swap(arr[pLeft], arr[pRight]);
                pLeft++;
                pRight--;
            }
        }
        quicksortHoare(arr, left, pRight);
        quicksortHoare(arr, pLeft, right);
    }
}

int main(){
    int n;
    cin >> n;
    vi arr;
    while(n--){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    quicksortHoare(arr, 0, arr.size() - 1);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << endl;
    }
    return 0;
}