#include <bits/stdc++.h>
using namespace std;

// using brute force
int largestRectangleAreaBruteForce(vector<int>& heights){
    int size = heights.size();
    int maxArea = -1;
    for(int i=0;i < size;i++){
        int idxLeft = i;
        int idxRight = i;

        while(idxLeft > 0 && heights[idxLeft] >= heights[i]){
            idxLeft--;
        }
        if (heights[idxLeft] < heights[i]) idxLeft++;

        while(idxRight < size - 1 && heights[idxRight] >= heights[i]){
            idxRight++;
        }
        if (heights[idxRight] < heights[i]) idxRight--;

        // cout << heights[i] * (idxRight - idxLeft + 1) << " " << idxLeft << " " << idxRight << endl;
        maxArea = max(maxArea,heights[i] * (idxRight - idxLeft + 1));
    }
    return maxArea;
}

int largestRectangleArea(vector<int>& heights){
    int size = heights.size();
    int maxArea = -1;
    stack<char> s; // empty stack
    for(int i=0;i< size;i++){
        if (s.empty()){
            s.push(i);
        }else {
            int boundTop = s.top() - 1; 
            while(heights[s.top()] > heights[i]){
                int idx = s.top();
                int height = heights[idx];
                s.pop();
                int boundBottom = 0;
                if (!s.empty()){
                    boundBottom = s.top();
                } 
                // calculate area
                int area = height * (boundTop - boundBottom + 1);
                maxArea = max(maxArea, area);

                if(s.empty()) break;
            }
            s.push(i);
        }

        // sisa stack
        int boundTop = s.top() - 1;
        while(!s.empty()){
            int idx = s.top();
            s.pop();
            int height = heights[idx];
            int boundBottom = 0;
            if (!s.empty()){
                boundBottom = s.top();
            }
            int area = height * (boundTop - boundBottom + 1);
            maxArea = max(maxArea, area);
        }
    }
    
    return maxArea;
}

int main(){
    // using brute force 2 pointer
    vector<int> heights;
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        heights.push_back(num);
    }
    cout << largestRectangleArea(heights) << endl;
    cout << largestRectangleAreaBruteForce(heights) << endl;
    return 0;
}