// Given a maze(2D matrix) with obstacles, starting from (0,0) you have to
// reach (n-1, n-1). If you are currently on (x,y), you can move to (x+1,y) or (x,y+1).
// You can not move to the walls.
// Idea: Try all the possible paths to see if you can reach (n-1,n-1)

// input
// 5
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1

// output:
// 1 0 0 0 0
// 1 1 1 1 0
// 0 0 0 1 0
// 0 0 0 1 1
// 0 0 0 0 1

#include <iostream>
using namespace std;

// takes the array, position x & y, and array size and returns true if the position is safe
// i.e. no blockage or not a '0' in our maze representation
bool isSafe(int **a, int x, int y, int n)
{
    if (x < n && y < n && a[x][y] == 1)
    {
        return true;
    }
    return false;
}

// returns true if a path is possible to reach end
// takes array (maze) starting position, array size(n*n)
// and a answer array which is filled by the path taken by the rat
bool ratMaze(int **a, int x, int y, int n, int **ans)
{
    // if reached destination, return true
    if ((x == (n - 1)) && (y == (n - 1)))
    {
        ans[x][y] = 1;
        return true;
    }
    // if the position is safe
    if (isSafe(a, x, y, n))
    {
        // mark that position as 1, i.e. rat takes that path
        ans[x][y] = 1;
        // we take two choices now
        if (ratMaze(a, x + 1, y, n, ans))
        {
            // we move right recusively and return true if that is true
            return true;
        }
        if (ratMaze(a, x, y + 1, n, ans))
        {
            // we move down and return true likewise
            return true;
        }
        // if we reached here that means that position we selected earlier didn't give a solution till end
        // so we backtrack and set this position as 0, a.k.a we backtrack
        ans[x][y] = 0;
        //and return false
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    //array declaration dynamically
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        // memory size allocated for size n*n
        arr[i] = new int[n];
    }
    //taking array input (maze)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    //creating solution array
    int **solArr = new int *[n];
    //assigning 0 to all positions in the array
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }
    cout << endl;
    //display the solution array, if rat maze has returned true
    if (ratMaze(arr, 0, 0, n, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

//  1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1