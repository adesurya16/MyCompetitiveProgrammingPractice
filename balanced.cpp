#include <bits/stdc++.h>
using namespace std;

void addSizeNode(vector<int> files_size, vector<vector<int>> child, int curIdx, vector<int> &sizeNode){
    if (child[curIdx].back() == -1){
        sizeNode[curIdx] = files_size[curIdx];
    }else{
        int sum = files_size[curIdx];
        for(int idx : child[curIdx]){
            addSizeNode(files_size, child, idx, sizeNode);
            sum += sizeNode[idx];
        }
        sizeNode[curIdx] = sum;
    }
}

int findMinBalanced(int curIdx, int curSum, vector<vector<int>> child, vector<int> sizeNode){
    queue<int> q;
    q.push(curIdx);
    int minim = INT_MAX;
    while(!q.empty()){
        curIdx = q.front();
        q.pop();
        for(int idx : child[curIdx]){
            int diff = abs(sizeNode[idx] - (curSum - sizeNode[idx]));
            minim = min(diff, minim);
            if (child[idx].back() != -1){
                q.push(idx);
            }
        }
    }
    return minim;
}

int mostBalancedPartition(vector<int> parent, vector<int> files_size) {
    vector<vector<int>> child;
    int idx = 0;
    int size = parent.size();
    while(size--){
        vector<int> v(1, -1);
        child.push_back(v);
    }
    
    for(int p : parent){
        
        if (p > -1){
            if(child[p].back() == -1){
               child[p].pop_back();
            }
            child[p].push_back(idx); 
        }
        idx++;
    }
    vector<int> sizeNode(size, 0);
    int curIdx = 0;
    addSizeNode(files_size, child, curIdx, sizeNode);
    return findMinBalanced(curIdx, sizeNode[curIdx], child, sizeNode);
}

int main(){
    
    return 0;
}