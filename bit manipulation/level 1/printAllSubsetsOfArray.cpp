// output
// 1
// 2
// 1 2
// 3
// 1 3
// 2 3
// 1 2 3

#include <iostream>
using namespace std;

void printAllSubsets(int a[], int n)
{
    // (1<<n) gives numbers in terms of 2 i.e. 2, 4, 8
    //we run loop from 0 to n=3 here
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            // this gives true if j bit is true
            if (i & (1 << j))
            {
                // so we print that corresponding value in array
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int a[] = {1, 2, 3};
    printAllSubsets(a, 3);
}
