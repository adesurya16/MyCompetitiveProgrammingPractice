// Largest Rectangle in a histogram https://www.spoj.com/problems/HISTOGRA/
#include <bits/stdc++.h>
using namespace std;
long long largestRectangleHistogram(vector<int> histogram)
{
    int size = histogram.size();
    int maxArea = -1;
    stack<char> s; // empty stack
    for (int i = 0; i < size; i++)
    {
        if (s.empty())
        {
            s.push(i);
        }
        else
        {
            int boundTop = s.top() - 1;
            while (histogram[s.top()] > histogram[i])
            {
                int idx = s.top();
                int height = histogram[idx];
                s.pop();
                int boundBottom = 0;
                if (!s.empty())
                {
                    boundBottom = s.top();
                }
                // calculate area
                int area = height * (boundTop - boundBottom + 1);
                maxArea = max(maxArea, area);

                if (s.empty())
                    break;
            }
            s.push(i);
        }

        // sisa stack
        int boundTop = s.top() - 1;
        while (!s.empty())
        {
            int idx = s.top();
            s.pop();
            int height = histogram[idx];
            int boundBottom = 0;
            if (!s.empty())
            {
                boundBottom = s.top();
            }
            int area = height * (boundTop - boundBottom + 1);
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;

    // create alghoritm
    // hint : stacks + ad hoc
}

int largestRectangleAreaBruteForce(vector<int> &heights)
{
    int size = heights.size();
    int maxArea = -1;
    for (int i = 0; i < size; i++)
    {
        int idxLeft = i;
        int idxRight = i;

        while (idxLeft > 0 && heights[idxLeft] >= heights[i])
        {
            idxLeft--;
        }
        if (heights[idxLeft] < heights[i])
            idxLeft++;

        while (idxRight < size - 1 && heights[idxRight] >= heights[i])
        {
            idxRight++;
        }
        if (heights[idxRight] < heights[i])
            idxRight--;

        // cout << heights[i] * (idxRight - idxLeft + 1) << " " << idxLeft << " " << idxRight << endl;
        maxArea = max(maxArea, heights[i] * (idxRight - idxLeft + 1));
    }
    return maxArea;
}

void solve(int nRec)
{
    // solve the problem here
    vector<int> h(nRec);
    for (int i = 0; i < nRec; i++)
    {
        cin >> h[i];
    }
    cout << largestRectangleAreaBruteForce(h) << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n > 0)
    {
        solve(n);
        cin >> n;
    }
    return 0;
}