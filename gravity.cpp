#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr){
    cout << arr[0];
    for(int i = 1;i < arr.size();i++){
        cout << " " << arr[i];
    }
}

int partition(vector<int> &arr, int left, int right){
    int pivot = arr[left];
    int pLeft = left - 1;
    int pRight = right + 1;
    while(true){
        do {
            pLeft++;
        }while(arr[pLeft] < pivot);

        do{
            pRight--;
        }while(arr[pRight] > pivot);

        if(pLeft >= pRight) return pRight;

        swap(arr[pLeft], arr[pRight]); 
    }
}

void quicksort(vector<int> &arr, int left, int right){
    if (left < right){
        int mid = partition(arr, left, right);
        // cout << "MID : " << mid << endl;
        // printArr(arr);
        // cout << endl;
        quicksort(arr, left, mid);
        quicksort(arr, mid + 1, right);
    }
}



int main(){
    // int maximum = 100;
    // vector<vector<int>> mat(maximum, vector<int>(maximum, 0));

    int n;
    cin >> n;
    vector<int> arr(n);

    // int height = -1;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    // quicksort(arr, 0 , n - 1);
    sort(arr.begin(), arr.end());
    // runtuh ke kanan
    printArr(arr);
    return 0;
}