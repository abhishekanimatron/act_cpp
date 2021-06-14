#include <iostream>
using namespace std;

// swap the elements at i, j indexes in array
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void dutchSort(int a[], int n)
{
    // intialize low, mid, high pointers
    int low = 0;
    int mid = 0;
    int high = n - 1;

    // from mid to high is unknown region, we loop throught that
    while (mid <= high)
    {
        // if mid element is zero we swap with low, so that zero appears earlier
        if (a[mid] == 0)
        {
            swap(a, low, mid);
            low++;
            mid++;
        }
        // if is 1, we just increment mid, making the elements between low and mid all ones
        else if (a[mid] == 1)
        {
            mid++;
        }
        // if is 2, we replace that with high index's element, so that 2s appear later
        else
        {
            swap(a, mid, high);
            high--;
        }
    }
}

int main()
{
    int a[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    //output: 0 0 1 1 1 1 2 2 2
    dutchSort(a, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
}