#include <iostream>
using namespace std;

bool sorted(int a[], int n)
{
    if (n == 1)
    {
        return true;
    }
    bool restOfArray = sorted(a + 1, n - 1);
    return (restOfArray && a[0] < a[1]);
}

int main()
{
    int a[] = {1, 2, 8, 4, 5};
    // output: 0
    // int a[] = {1, 2, 3, 4, 5};
    // //output: 1
    cout << sorted(a, 5) << endl;
}