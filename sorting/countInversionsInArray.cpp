//using merge sort algo for counting inversions

// input :
// 3
// 3 2 1

// output:
// 3
#include <iostream>

long long merge(int arr[], int l, int mid, int r)
{
    long long inversions = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    //array declarations for temporary arrays which will be later merged into single sorted array
    int a[n1];
    int b[n2];

    //filling array, left half
    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];

    //filling array, right half
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l; //pointers, index of merged array
    //while either of array is not ended
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j]) //lesser value is placed first in original array
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            // since here a[i] > b[j], there is an inversion
            inversions += n1 - i;
            // elements in a[i] will be greater than b[j] as it is smaller than a[i]
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1) //remaining values in the temporary array
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inversions;
}

//as inversions can be many, large in number we take long long data type
long long mergeSortIn(int a[], int l, int r)
{
    long long inversions = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        // inversions in left (recursed)
        inversions += mergeSortIn(a, l, mid);
        // inversions in right (recursed)
        inversions += mergeSortIn(a, mid + 1, r);
        // inversions when merging
        inversions += merge(a, l, mid, r);
    }
    return inversions;
}
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << mergeSortIn(a, 0, n - 1);
}