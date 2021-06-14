#include <iostream>
using namespace std;

// swap the elements at i, j indexes in array
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// wave sort one element small next bigger, next smaller, next bigger and so on
void waveSort(int a[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        // if the element is greater than its previous element, swap them
        if (a[i] > a[i - 1])
        {
            swap(a, i, i - 1);
        }
        // if the element is greater than its next element, swap them
        if (a[i] > a[i + 1] && i <= n - 2)
        {
            swap(a, i, i + 1);
        }
    }
}

int main()
{
    int a[] = {1, 3, 4, 7, 5, 6, 2};
    //output: 3 1 7 4 6 2 5
    waveSort(a, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
}