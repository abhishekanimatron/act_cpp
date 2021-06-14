#include <iostream>
#include <algorithm>
using namespace std;

//takes array and size, sorts the array
void countSort(int a[], int n)
{
    // calculating maximum element of array and storing it in k
    int k = a[0]; //first element in k
    for (int i = 0; i < n; i++)
    {
        k = max(k, a[i]);
    }

    // making our count array
    // should be k but taken here as 10, due to reason of we can't dynamically allocate memory
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        // for each element we store its count in that index(element's value)
        count[a[i]]++;
    }
    // we modify count array by replacing the value of each with sum upto that inex
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }
    // array which is sorted, will be made
    int ans[n];

    // making the answer array
    for (int i = n - 1; i >= 0; i--)
    {
        // traversing from end of original array, going to that index in count array, decrementing
        // that value in count array going to that index in answer array, and placing the element
        // of original array in this place
        ans[--count[a[i]]] = a[i];
    }
    // making the original array througth answer array
    for (int i = 0; i < n; i++)
    {
        a[i] = ans[i];
    }
}

int main()
{
    int a[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    // output : 1 1 2 3 3 3 4 4 6
    countSort(a, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
}