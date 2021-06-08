
#include <iostream>
using namespace std;

// this function gives whether a pair exists or not
bool pairSum(int a[], int arraySize, int targetSum)
{
    int low = 0;
    int high = arraySize - 1;

    while (low < high)
    {
        // if the pointers give targetSum we return true
        if (a[low] + a[high] == targetSum)
        {
            cout << low << " " << high << endl;
            return true;
        }
        // else if less increase left/low pointer
        else if (a[low] + a[high] < targetSum)
            low++;
        else
            // else decrease high/right pointer
            high--;
    }
    // if here, that means no such pair exists
    return false;
}

int main()
{
    // given array is sorted
    int a[] = {1, 1, 3, 4, 5};
    int k = 7;
    cout << pairSum(a, 5, k) << endl;
}