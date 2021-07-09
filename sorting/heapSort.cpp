#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    // root is intialized as largest
    int largest = i;
    // left and right child
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // if left child is larger make it root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // if right child is larger make it root
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // if largest is changed, that is not root
    if (largest != i)
    {
        // swap this root, with new largest value
        swap(arr[i], arr[largest]);
        // heapify with this new root
        heapify(arr, n, largest);
    }
}

// does heap sort of array
void heapSort(int arr[], int n)
{
    // from first non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
        // build heap
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
    // 5 6 7 11 12 13
}