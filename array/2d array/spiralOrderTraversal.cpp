// input
// 5 6
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

// output

// 1 2 3 4 5 6 12 18 24 30 29 28 27 26 25 19 13 7 8 9 10 11 17 23 22 21 20 14 15 16

#include <iostream>
using namespace std;
int main()
{
    //n: no. of rows
    //m: no. of columns
    int n, m;
    cin >> n >> m;
    int a[n][m];
    // 2d array input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int rowStart = 0, rowEnd = n - 1;
    int columnStart = 0, columnEnd = m - 1;

    // printing loop
    while (rowStart <= rowEnd && columnStart <= columnEnd)
    {
        //for printing top/up/starting row
        if (rowStart <= rowEnd && columnStart <= columnEnd)
            for (int column = columnStart; column <= columnEnd; column++)
                cout << a[rowStart][column] << " ";
        rowStart++;

        //for printing right/end column
        if (rowStart <= rowEnd && columnStart <= columnEnd)
            for (int row = rowStart; row <= rowEnd; row++)
                cout << a[row][columnEnd] << " ";
        columnEnd--;

        //for printing bottom row
        if (rowStart <= rowEnd && columnStart <= columnEnd)
            for (int column = columnEnd; column >= columnStart; column--)
                cout << a[rowEnd][column] << " ";
        rowEnd--;

        //for printing left row
        if (rowStart <= rowEnd && columnStart <= columnEnd)
            for (int row = rowEnd; row >= rowStart; row--)
                cout << a[row][columnStart] << " ";
        columnStart++;
    }
}