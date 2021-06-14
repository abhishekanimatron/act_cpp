
#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1; //array sizes in 2 halves
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
}

void mergeSort(int arr[], int l, int r)
{
    // condition
    if (l < r)
    {
        // split the array by half
        int mid = (l + r) / 2;
        // recursive call for starting (left) to mid, left part
        mergeSort(arr, l, mid);
        // recursive call for mid to end, right part
        mergeSort(arr, mid + 1, r);
        //merge the two half arrays
        merge(arr, l, mid, r); //merging function
    }
}

int main()
{
    int arr[] = {5, 4, 2, 3, 1};
    //output:
    // 1 2 3 4 5
    mergeSort(arr, 0, 4);       //arr,first index,last index
    for (int i = 0; i < 5; i++) //output printing
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}