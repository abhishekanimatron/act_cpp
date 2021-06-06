/*
input
5
output
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
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
            if ((i + j) % 2)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}