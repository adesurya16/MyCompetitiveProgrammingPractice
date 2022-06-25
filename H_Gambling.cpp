#include <bits/stdc++.h>
using namespace std;

// void printKadane(int n, vector<int> arr)
// {
//     vector<int> tmp(n, -1);
//     for (int i : arr)
//     {
//         tmp[i] = 1;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << tmp[i] << " ";
//     }
//     cout << endl;
// }

vector<int> maxSubKadane(vector<int> arr)
{
    int maxValueGlobal = 0;
    int maxValueLocal = 0;
    int leftIndexGlobal = 0;
    int rightIndexGlobal = 0;
    int leftIndexLocal = 0;
    int rightIndexLocal = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            maxValueGlobal = 1;
            maxValueLocal = 1;
            leftIndexLocal = arr[i];
            rightIndexLocal = arr[i];
            leftIndexGlobal = arr[i];
            rightIndexGlobal = arr[i];
        }
        else
        {
            int currentValue = maxValueLocal + (-1) * (arr[i] - arr[i - 1] - 1) + 1;
            if (currentValue > 1)
            {
                maxValueLocal = currentValue;
                // leftIndexLocal = leftIndexLocal;
                rightIndexLocal = arr[i];
                if (maxValueLocal > maxValueGlobal)
                {
                    maxValueGlobal = currentValue;
                    leftIndexGlobal = leftIndexLocal;
                    rightIndexGlobal = rightIndexLocal;
                }
            }
            else
            {
                maxValueLocal = 1;
                leftIndexLocal = arr[i];
                rightIndexLocal = arr[i];
            }
        }
    }
    vector<int> res;
    res.push_back(maxValueGlobal);
    res.push_back(leftIndexGlobal);
    res.push_back(rightIndexGlobal);
    // index of the max sum
    // cout << "max global : " << maxValueGlobal << endl;
    // cout << "left index : " << leftIndexGlobal << endl;
    // cout << "right index : " << rightIndexGlobal << endl;
    return res;
}
void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x].push_back(i);
    }
    int maxValue = 0;
    int number = 0;
    int leftIndexValue = 0;
    int rightIndexValue = 0;
    // vector<int> arr(n);
    for (const auto &[key, value] : m)
    {
        // int size = value.size();
        // cout << key << " -> ";
        // printKadane(n, value);
        vector<int> arr = maxSubKadane(value);
        int tmpMaxValue = arr[0];
        int tmpLeftIndexValue = arr[1];
        int tmpRightIndexValue = arr[2];
        if (tmpMaxValue > maxValue)
        {
            maxValue = tmpMaxValue;
            number = key;
            leftIndexValue = tmpLeftIndexValue;
            rightIndexValue = tmpRightIndexValue;
        }
        // cout << key << " " << value.size() << endl;
        // for (int i = 0; i < size; i++)
        // {
        //     cout << value[i] << " ";
        // }
        // cout << endl;
    }
    cout << number << " " << leftIndexValue + 1 << " " << rightIndexValue + 1 << endl;
}

int main()
{
    int cases = 1; // 1 or more cases
    cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}