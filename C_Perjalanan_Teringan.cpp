// https://tlx.toki.id/courses/competitive/chapters/13/problems/C

#include <bits/stdc++.h>
using namespace std;
bool isValid(int x, int y, int boundX, int boundY)
{
    return (x >= 0 && x < boundX && y >= 0 && y < boundY);
}
void floodFill(int x, int y, int boundX, int boundY, vector<vector<int>> &board, vector<vector<bool>> &boardBool)
{
    if (isValid(x, y, boundX, boundY) && board[x][y] != -1 && !boardBool[x][y])
    {
        // cout << x << " " << y << endl;
        boardBool[x][y] = 1;
        floodFill(x - 1, y, boundX, boundY, board, boardBool); // north
        floodFill(x, y + 1, boundX, boundY, board, boardBool); // east
        floodFill(x + 1, y, boundX, boundY, board, boardBool); // south
        floodFill(x, y - 1, boundX, boundY, board, boardBool); // west
    }
}

int findMax(int x, int y, vector<vector<int>> &board, vector<vector<bool>> &boardBool)
{
    int minBoard = INT_MAX;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (boardBool[i][j])
            {
                minBoard = min(minBoard, board[i][j]);
            }
        }
    }
    return minBoard;
}

// void printBoard(vector<vector<bool>> arr)
// {
//     int x = arr.size();
//     int y = arr[0].size();
//     for (int i = 0; i < x; i++)
//     {
//         for (int j = 0; j < y; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// void printBoardInt(vector<vector<int>> arr)
// {
//     int x = arr.size();
//     int y = arr[0].size();
//     for (int i = 0; i < x; i++)
//     {
//         for (int j = 0; j < y; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

void solve(int cases = 1)
{
    // solve the problem here
    int x, y; // max 1000
    cin >> x >> y;
    vector<vector<int>> board = vector(x, vector<int>(y));
    vector<vector<bool>> boardBool = vector(x, vector<bool>(y, 0));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> board[i][j];
        }
    }
    int xStart, xFinish, yStart, yFinish;
    cin >> xStart >> yStart;
    cin >> xFinish >> yFinish;
    // cout << "board" << endl;
    // printBoardInt(board);
    // do floodfill true from xStart and yStart (ignore -1 and accept 0 or more in board)
    floodFill(xStart - 1, yStart - 1, x, y, board, boardBool);
    // if xFinish and yFinish is true getminimum value
    // cout << "board bool" << endl;
    // printBoard(boardBool);
    if (boardBool[xFinish - 1][yFinish - 1])
    {
        cout << findMax(x, y, board, boardBool) << endl;
    }
    // always true (guaranteed)
}

int main()
{
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}