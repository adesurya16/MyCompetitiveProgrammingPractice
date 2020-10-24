#include <bits/stdc++.h>
using namespace std;

void print(int a[], int n){
    cout << a[0];
    for(int i=1;i<n;i++){
        cout << " " << a[i]; 
    // printf("\n");
    }
    cout << endl;
}

void heapPermutation(int a[], int size, int n) 
{ 
    // if size becomes 1 then prints the obtained 
    // permutation 
    if (size == 1) 
    { 
        print(a, n); 
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a, size-1, n); 
  
        // if size is odd, swap first and last 
        // element 
        if (size % 2 == 1) 
            swap(a[0], a[size-1]); 
  
        // If size is even, swap ith and last 
        // element 
        else
            swap(a[i], a[size-1]); 
    } 
} 

int main(){
    int a[] = {1, 2, 3, 4}; 
    int n = sizeof a/sizeof a[0]; 
    heapPermutation(a, n, n); 
    return 0;
}