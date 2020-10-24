#include <bits/stdc++.h>
using namespace std;
// typedef char[10] c;
// typedef struct pairs {
//     char names[10];
//     char numbers[6];
// } Pairs;

const int MAX = 100000;
const int MAX_NUMBER = 7;
const int MAX_NAME = 11;

// string bSearch(vector<pair<string, string>> myVec, string name){
//     int left = 0;
//     int right = myVec.size() - 1;
//     while(left <= right){
//         int mid = left + (right - left)/2;
//         int m = myVec[mid].first.compare(name);
//         if(m == 0){
//             return myVec[mid].second;
//         }
//         if(m < 0){
//             left = mid + 1;
//         }else{
//             right = mid - 1;
//         }
//     }
//     return "NIHIL";
// }

// Pairs bSearch(vector<Pairs> v, char name[10]){
//     int left = 0;
//     int right = v.size() - 1;
//     while(left <= right){
//         int mid = left + (right - left)/2;
//         int m = strcmp(v[mid].names, name);
//         if(m == 0){
//             printf("%s", v[mid].numbers);
//             return v[mid];
//         }
//         if(m < 0){
//             left = mid + 1;
//         }else{
//             right = mid - 1;
//         }
//     }
//     Pairs p;
//     printf("NIHIL\n");
//     strcpy(p.numbers, "NIHIL");
//     return p;
// }

int bSearch(char names[MAX][MAX_NAME], int len, char name[MAX_NAME]){
    int left = 0;
    int right = len; // a - 1
    while(left <= right){
        int mid = left + (right - left)/2;
        int diff = strcmp(names[mid], name);
        if (diff == 0){
            return mid;
        }
        if(diff < 0){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    char numbers[MAX][MAX_NUMBER];
    char names[MAX][MAX_NAME];
    int i = 0;
    while(a--){
        // char name[10];
        // char number[6];
        // scanf("%s %s", name, number);
        scanf("%s", names[i]);
        scanf("%s", numbers[i]);
        // strcpy(names[i], name);
        // strcpy(numbers[i], number);
        i++;
    }

    
    while(b--){
        char name[10];
        scanf("%s", name);
        int idx = bSearch(names, i, name);
        if(idx == -1){
            printf("NIHIL\n");
        }else printf("%s\n", numbers[idx]);
    }

    return 0;
}