#include <bits/stdc++.h>
using namespace std;

vector<int> table;

void enumerate(int n)
{
  for (int i = 0; i < (1 << n); i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        printf("%d ", table[j]);
      }
    }
    printf("\n");
  }
}

int main()
{
  int N;
  table = vector<int>(1000);
  scanf("%d", &N);
  cout << N << endl;
  ;
  //   vector<int> table[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &table[i]);
  }
  // for(int i = 0;i<N;i++){
  //   printf("%d\n", table[i]);
  // }
  enumerate(N);
  return 0;
}