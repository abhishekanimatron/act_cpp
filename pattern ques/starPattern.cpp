/*
input
4
output
      *
    * * *
  * * * * *
* * * * * * *
* * * * * * *
  * * * * *
    * * *
      *
*/

#include <iostream>
using namespace std;

void printPattern(int i, int row)
{
    for (int j = 1; j <= row - i; j++)
        cout << "  ";

    for (int j = 1; j <= 2 * i - 1; j++)
        cout << "* ";

    cout << endl;
}

int main()
{
    int row;
    cin >> row;
    for (int i = 1; i <= row; i++)
        printPattern(i, row);
    for (int i = row; i > 0; i--)
        printPattern(i, row);
}