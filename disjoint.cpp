#include <bits/stdc++.h>
using namespace std;
typedef map<int, int> mii;
class DisjSet{
    int maxsize;
    mii parent;
    mii size;

    public:
        DisjSet(){
            this->maxsize = 1;
        }

        int findParent(int x){
            if (parent.find(x) != parent.end()){
                if (parent[x] != x){
                    parent[x] = findParent(parent[x]);
                    size[x] = 1;
                }
            }else{
                parent[x] = x;
                size[x] = 1;
            }
            return parent[x];
        }

        void unionSet(int x, int y){
            int parentX = findParent(x);
            int parentY = findParent(y);

            if (parentX != parentY){
                if ((size[parentX] + size[parentY]) > this->maxsize){
                    this->maxsize = size[parentX] + size[parentY];
                }

                if (parentX < parentY){
                    parent[parentY] = parentX;
                    size[parentX] = size[parentX] + size[parentY];
                }else{
                    parent[parentX] = parentY;
                    size[parentY] = size[parentX] + size[parentY];
                } 
            }
        }

        int getMaxSize(){
            return this->maxsize;
        }
};

int main(){
    DisjSet *dSet = new DisjSet();
    int n;
    scanf("%d", &n);
    while(n--){
        int x,y;
        scanf("%d %d", &x, &y);
        dSet->unionSet(x, y);
        printf("%d\n", dSet->getMaxSize());
    }
    return 0;
}