/*
bool isVerticalValid(vector<vector<int>>& boards, int colIndex){
        int row = boards.size();
        set<int> s;
        for(int i = 0;i < row;i++){
            if (boards[i][colIndex] != 0){
                if (s.find(boards[i][colIndex]) == s.end()) {
                    s.insert(boards[i][colIndex]);
                }else{
                    return 0;
                }
            }

        }
        return 1;
    }

    bool isHorizontalValid(vector<vector<int>>& boards, int rowIndex){
        int col = boards[0].size();
        set<int> s;
        for(int i = 0;i < col;i++){
            if (boards[rowIndex][i] != 0){
                if (s.find(boards[rowIndex][i]) == s.end()){
                    s.insert(boards[rowIndex][i]);
                }else {
                    return 0;
                }
            }
        }
        return 1;
    }

    bool isPartValid(vector<vector<int>>& boards, int rowIndex, int colIndex){
        int row = boards.size();

        int col = boards[0].size();

        int xMin, xMax, yMin, yMax;

        // find xMin, xMax depend on rowIndex
        if (rowIndex >= 0 && rowIndex <= 2){
            xMin = 0;
            xMax = 2;
        }else if (rowIndex >= 3 && rowIndex <= 5){
            xMin = 3;
            xMax = 5;
        }else{
            xMin = 6;
            xMax = 8;
        }

        // find yMin, yMax depend on colIndex
        if (colIndex >= 0 && colIndex <= 2){
            yMin = 0;
            yMax = 2;
        }else if (colIndex >= 3 && colIndex <= 5){
            yMin = 3;
            yMax = 5;
        }else{
            yMin = 6;
            yMax = 8;
        }

        // other part validation
        set<int> s;

        for(int i = xMin;i <= xMax;i++){
            for(int j = yMin;j <= yMax;j++){
                if (boards[i][j] != 0) {
                    if (s.find(boards[i][j]) == s.end()){
                        s.insert(boards[i][j]);
                    }else{
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    bool isSolve(vector<pair<int, int>> &points, vector<vector<int>> &boards, int start){
        if (start == points.size()) return 1;
        int x = points[start].first;
        int y = points[start].second;

    }

    vector<vector<char>> toCharArr(vector<vector<int>>& boards){
        int row = boards.size();
        int col = boards[0].size();
        vector<vector<char>> arr(row, vector<int>(col));
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col; j++){
                string str = to_string(boards[i][j]);
                arr[i][j] = str[0];
            }
        }
        return arr;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // to vector int (. -> 0)
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> boards(row, vector<int>(col));
        vector<pair<int, int>> points;
        for(int i = 0;i < row;i++){
            for(int j = 0; j < col;j++){
                if (board[i][j] == '.'){
                    boards[i][j] = 0;
                    points.push_back({i, j});
                }else boards[i][j] = (int)board[i][j] - (int)'1' + 1;
            }
        }
        int start = 0;
        bool isSolve = solve(points, boards, start);
        return toCharArr(boards);
    }

*/

// solve sudoku 9x9 only
#include <bits/stdc++.h>
using namespace std;

int idxSpecArea(int x, int y)
{
    // special area
    // 0 [0, 2] and [0, 2]
    // 1 [0, 2] and [3, 5]
    // 2 [0, 2] and [6, 8]
    // 3 [3, 5] and [0, 2]
    // 4 [3, 5] and [3, 5]
    // 5 [3, 5] and [6, 8]
    // 6 [6, 8] and [0, 2]
    // 7 [6, 8] and [3, 5]
    // 8 [6, 8] and [6, 8]
    if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
    {
        return 0;
    }
    else if (x >= 0 && x <= 2 && y >= 3 && y <= 5)
    {
        return 1;
    }
    else if (x >= 0 && x <= 2 && y >= 6 && y <= 8)
    {
        return 2;
    }
    else if (x >= 3 && x <= 5 && y >= 0 && y <= 2)
    {
        return 3;
    }
    else if (x >= 3 && x <= 5 && y >= 3 && y <= 5)
    {
        return 4;
    }
    else if (x >= 3 && x <= 5 && y >= 6 && y <= 8)
    {
        return 5;
    }
    else if (x >= 6 && x <= 8 && y >= 0 && y <= 2)
    {
        return 6;
    }
    else if (x >= 6 && x <= 8 && y >= 3 && y <= 5)
    {
        return 7;
    }
    else
    {
        return 8;
    }
}

bool isRow(int x, vector<set<char>> &rowSets, char target)
{
    return rowSets[x].find(target) == rowSets[x].end();
}

bool isCol(int y, vector<set<char>> &colSets, char target)
{
    return colSets[y].find(target) == colSets[y].end();
}

bool isArea(int x, int y, vector<set<char>> &specAreaSets, char target)
{
    int idx = idxSpecArea(x, y);
    return specAreaSets[idx].find(target) == specAreaSets[idx].end();
}

char toDigChar(int digit)
{
    string str = to_string(digit);
    return str[0];
}

bool isValidSudoku(vector<vector<char>> &board, vector<pair<int, int>> points, vector<set<char>> &rowSets,
                   vector<set<char>> &colSets, vector<set<char>> &specAreaSets, int start)
{
    // backtracking
    if (start == points.size())
    {
        return 1;
    }
    int x = points[start].first;
    int y = points[start].second;
    for (int i = 1; i <= 9; i++)
    {
        char c = toDigChar(i);
        if (isRow(x, rowSets, c) && isCol(y, colSets, c) && isArea(x, y, specAreaSets, c))
        {
            int idx = idxSpecArea(x, y);
            // init
            rowSets[x].insert(c);
            colSets[y].insert(c);
            specAreaSets[idx].insert(c);
            board[x][y] = c;
            if (isValidSudoku(board, points, rowSets, colSets, specAreaSets, start + 1))
            {
                return 1;
            }
            // backtrack
            rowSets[x].erase(c);
            colSets[y].erase(c);
            specAreaSets[idx].erase(c);
            board[x][y] = '.';
        }
    }
    return 0;
}

void solveSudoku(vector<vector<char>> &board)
{
    int row = 9;
    int col = 9;

    // return using input/output variable board

    // init rowSets, colSets, specAreaSet
    vector<set<char>> rowSets(9);
    vector<set<char>> colSets(9);
    vector<set<char>> specAreaSets(9);

    // init vector of point null value (point of problem)
    vector<pair<int, int>> points;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == '.')
            {
                points.push_back({i, j});
            }
            else
            {
                char c = board[i][j];
                rowSets[i].insert(c);
                colSets[j].insert(c);
                int idx = idxSpecArea(i, j);
                specAreaSets[idx].insert(c);
            }
        }
    }
    int start = 0;
    bool b = isValidSudoku(board, points, rowSets, colSets, specAreaSets, start);
}

void solve(int cases = 1)
{
    // solve the problem here
    vector<vector<char>> board(9, vector<char>(9));

    // input assume valid input
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    // proses
    solveSudoku(board);

    // output
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
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