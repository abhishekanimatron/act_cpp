
//                __                         __   .__
//   ____   _____/  |_  __  _  _____________|  | _|__| ____    ____
//  /    \ /  _ \   __\ \ \/ \/ /  _ \_  __ \  |/ /  |/    \  / ___\ 
// |   |  (  <_> )  |    \     (  <_> )  | \/    <|  |   |  \/ /_/  >
// |___|  /\____/|__|     \/\_/ \____/|__|  |__|_ \__|___|  /\___  /
//      \/                                       \/       \//_____/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
void helper(int r, int c, vector<vector<char>> &a, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> row, vector<map<int, int>> col)
{
    if (r == 9)
    {
        for (auto it : a)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    // last column?, next row
    if (c == 9)
    {
        helper(r + 1, 0, a, mp, row, col);
        return;
    }
    // if not empty switch to next column
    if (a[r][c] != '.')
    {
        helper(r, c + 1, a, mp, row, col);
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        int rw = r / 3, cl = c / 3;
        if (!mp[{rw, cl}][i] && !row[r][i] && col[c][i])
        {
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c] = i + '0';
            helper(r, c + 1, a, mp, row, col);
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = '.';
        }
    }
}

void solveSudoku(vector<vector<char>> &a)
{
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] != '.')
            {
                // if the cell is not empty, make that number true in our map
                mp[{i / 3, j / 3}][a[i][j] - '0'] = 1; //3x3 grid
                row[i][a[i][j] - '0'] = 1;             //ith row,
                col[j][a[i][j] - '0'] = 1;             //ith column
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}

int main()
{
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    solveSudoku(sudoku);
    return 0;
}