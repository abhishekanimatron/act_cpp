// You have to place n queens on an nxn chessboard.
// Idea: Try all the possible positions for the queen. isSafe functions check whether
// the current position is safe or not.
// Input:
// A single integer n
// Output:
// n x n matrix, where one denotes queen, and 0 for an empty cell.

// input: 4

// output:
// 0 1 0 0
// 0 0 0 1
// 1 0 0 0
// 0 0 1 0

#include <iostream>
using namespace std;

// takes the array, position x & y, and array size 'n' and returns true if the position is safe
// i.e. no queen can attack this queen (by chess's rules)
bool isSafe(int **a, int x, int y, int n)
{
    //check for straight up
    for (int row = 0; row < x; row++)
    {
        // check for each row if that column 'y' has a queen placed in it, as it can attack straight down
        //check from 0th row to that row 'x' position, return false if there is a 1, meaning a queen is present there
        if (a[row][y] == 1)
        {
            return false;
        }
    }

    //check for diagonals
    // it can attack diagonally

    //left diagonal
    int row = x;
    int column = y;
    // for row & column limits
    while (row >= 0 && column >= 0)
    {
        // check for upto left diagonal
        if (a[row][column] == 1)
        {
            // return false if there is a 1, meaning a queen is present there
            return false;
        }
        // previous row and previous column
        row--;
        column--;
    }

    //right diagonal
    row = x;
    column = y;
    // for row & column limits
    while (row >= 0 && column < n)
    {
        // check for upto right diagonal
        if (a[row][column] == 1)
        {
            // return false if there is a 1, meaning a queen is present there
            return false;
        }
        // previous row and next column
        row--;
        column++;
    }
    return true;
}

bool nQueenSolver(int **a, int x, int n)
{
    //x has reached end, no more queens to placed anymore
    if (x >= n)
    {
        return true;
    }
    for (int column = 0; column < n; column++)
    {
        // if position is safe, place a queen there
        if (isSafe(a, x, column, n))
        {
            a[x][column] = 1;
            // recursively call for next row
            if (nQueenSolver(a, x + 1, n))
            {
                return true;
            }
            // reached here, that means recursively it couldn't find a solution, so we backtrack and remove
            // our queen from there, placing a '0'
            a[x][column] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **a = new int *[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    if (nQueenSolver(a, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
