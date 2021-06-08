// input
// 3
// 1 2 3
// 4 5 6
// 7 8 9

// output
// 1 4 7
// 2 5 8
// 3 6 9

#include <iostream>
using namespace std;
int main()
{
    //n: no. of rows,columns
    int n;
    cin >> n;
    int a[n][n];
    // 2d array input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            // swapping
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }

    // printing output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}