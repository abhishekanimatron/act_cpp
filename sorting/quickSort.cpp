#include <iostream>
using namespace std;

// swap the elements at i, j indexes in array
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// picks pivot element and partions the array with second part being bigger
// and returns the pivot's index in sorted array
int partition(int a[], int left, int right)
{
    //say array is 6,3,9,5,2,8,7
    // pick last element as pivot
    int pivot = a[right]; //7
    int i = left - 1;     //intialized before array (left) started

    //for j from left to right
    for (int j = left; j < right; j++)
    {
        // if value at j is less than the selected pivot, we swap element at i+1 and j (swap does that)
        //doing this for all, all the bigger ones get on the right side
        if (a[j] < pivot)
        {
            i++;
            swap(a, i, j);
        }
    }
    //the position of pivot is at i+1, because all elements to the right of it are bigger than the pivot
    swap(a, i + 1, right);
    //returns the pivot's index
    return i + 1;
}
void quickSort(int a[], int left, int right)
{
    if (left < right)
    {
        // gets the position of a random pivot element in the sorted array
        int pivot = partition(a, left, right);
        // recurse for left part of pivot
        quickSort(a, left, pivot - 1);
        // recurse for right part of pivot
        quickSort(a, pivot + 1, right);
    }
}

int main()
{
    int a[] = {5, 4, 2, 3, 1};
    //output:
    // 1 2 3 4 5
    quickSort(a, 0, 4);         //a,first index,last index
    for (int i = 0; i < 5; i++) //output printing
    {
        cout << a[i] << " ";
    }
    cout << endl;
}