// input
// 3 4 3
// 2 4 1 2
// 8 4 3 6
// 1 7 9 5
// 1 2 3
// 4 5 6
// 7 8 9
// 4 5 6

// output
// 33 42 51
// 69 90 111
// 112 134 156

#include <iostream>
using namespace std;
int main()
{
    //n1,n2,n3: no. of row/columns,e.g. 3x3 * 4x3 = 3x3
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    // matrix arrays
    int m1[n1][n2];
    int m2[n2][n3];

    // input for first matrix
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            cin >> m1[i][j];

    // input for second matrix
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n3; j++)
            cin >> m2[i][j];

    // initialization of product matrix
    int product[n1][n3];
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n3; j++)
            product[i][j] = 0;

    // calculating product matrix
    // multiply first matrix's rows
    for (int i = 0; i < n1; i++)
    {
        // with second matrix's columns
        for (int j = 0; j < n3; j++)
        {
            for (int k = 0; k < n2; k++)
            {
                //product is added to get a cell in matrix
                product[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
            cout << product[i][j] << " ";
        cout << endl;
    }
}
