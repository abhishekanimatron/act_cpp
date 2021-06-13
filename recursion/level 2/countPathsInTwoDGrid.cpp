#include <iostream>
using namespace std;

//counts number of paths from 0 to n-1, square (n*n) grid's  dimensions
int countPaths(int n, int i, int j)
{
    if (i >= n || j >= n)
    {
        // if it reaches out of bounds
        return 0;
    }
    if (i == n - 1 && j == n - 1)
    {
        // if reached the destination
        return 1;
    }
    // we go down once, right once (only movements allowed), recursively and add them up giving total
    return countPaths(n, i + 1, j) + countPaths(n, i, j + 1);
}

int main()
{
    cout << countPaths(3, 0, 0) << endl;
    //output: 6
}