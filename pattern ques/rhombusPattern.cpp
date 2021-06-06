/*
input
5
output
        * * * * *
      * * * * *
    * * * * *
  * * * * *
* * * * *
*/

#include <iostream>
using namespace std;

int main()
{
    int row;
    cin >> row;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < row; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
}