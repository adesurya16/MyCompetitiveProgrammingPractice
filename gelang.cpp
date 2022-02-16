#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x;
    int y;
    int rad;
} ring;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    ring r1, r2;
    cin >> r1.x >> r1.y >> r1.rad;
    cin >> r2.x >> r2.y >> r2.rad;
    int rr = (r1.rad + r2.rad) * (r1.rad + r2.rad);
    int distance = (r1.x - r2.x) * (r1.x - r2.x) + (r1.y - r2.y) * (r1.y - r2.y); // circle formula
    // lihat apakah r1 didalam r2 ataupun sebaliknya
    // jika didalam proses

    // jika diluar proses
    return 0;
}