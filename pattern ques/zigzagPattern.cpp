/*
input
9
output
9
    *       *
  *   *   *   *
*       *       *
*/

#include <iostream>
using namespace std;

int main()
{
    int col;
    cin >> col;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (!((i + j) % 4) || ((i == 2) && !(j % 4)))
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}