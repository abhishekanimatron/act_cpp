#include <iostream>
using namespace std;
//array and size of array :n
int uniqueNumber(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // ^ :xor operator
        // xoring with the number itself gives zero so only the unique number remains finally
        sum = sum ^ a[i];
    }
    return sum;
}

int main()
{
    int a[] = {1, 2, 3, 7, 1, 2, 3};
    cout << uniqueNumber(a, 7);
    //output: 7
}