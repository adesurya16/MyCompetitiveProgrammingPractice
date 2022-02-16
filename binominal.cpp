#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;


#define TC(t) while(t--);
#define endl "\n";
#define watch(x) cout << (#x) << " : " << (x) << endl
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)

int main(){
    int maximum = 1000 + 1;
    vector<vll> arr(maximum);
    for(int i = 0;i < maximum;i++){
        arr[i] = vll(i + 1);
        for(int j = 0;j < i + 1;j++){
            if(i == 0 || j == 0 || j == i){
                arr[i][j] = 1;
            }else {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
    }
    
    int t;
    // si(t);
    cin >> t;
    
    while(t--){
        int num;
        si(num);
        if (num == 0){
            cout << 1 << endl;
        }else{
            int A = num;
            int B = 0;
            for(int i = 0;i < arr[num].size(); i++){
                if (i > 0){
                    cout << "+";
                }
                if (arr[num][i] > 1){
                    cout << arr[num][i];
                }

                if(A > 1){
                    cout << "A^" << A;
                }else if(A == 1){
                    cout << "A";
                }
                A--;

                if(B > 1){
                    cout << "B^" << B;
                }else if(B == 1){
                    cout << "B";
                }
                B++;
            }
            cout << endl;    
        }
    }

    // for(int i = 0;i < maximum;i++){
    //     // pi(arr[i].size());
    //     for(int j = 0;j < arr[i].size();j++){
    //         cout << arr[i][j] << " ";
    //     }       
    //     cout << endl;
    // }
    return 0;
}