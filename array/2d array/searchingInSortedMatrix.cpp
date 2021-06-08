// input
// 3 3 9
// 1 2 3
// 4 5 6
// 7 8 9

// output
// found

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int matrix[n][m];

    int searchFor;
    cin >> searchFor;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // starting from top right
    int row = 0, column = m - 1;
    bool elementFound = false;
    while (row < n && column >= 0)
    {
        if (matrix[row][column] == searchFor)
            elementFound = true;
        if (matrix[row][column] > searchFor)
            column--;
        else
            row++;
    }
    if (elementFound)
        cout << "found" << endl;
    else
        cout << "not found" << endl;
}