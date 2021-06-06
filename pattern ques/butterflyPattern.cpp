/*
input
5
output
*                 *
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
* * * * * * * * * *
* * * *     * * * *
* * *         * * *
* *             * *
*                 *
*/

#include <iostream>
using namespace std;

int main()
{
    int row;
    cin >> row;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*"
                 << " ";
        }
        int spaces = 2 * row - 2 * i;
        for (int j = 0; j < spaces; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*"
                 << " ";
        }

        cout << endl;
    }
    for (int i = row; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*"
                 << " ";
        }
        int spaces = 2 * row - 2 * i;
        for (int j = 0; j < spaces; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*"
                 << " ";
        }

        cout << endl;
    }
}