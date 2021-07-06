// We rotate an ascending order sorted array at some pivot unknown to you beforehand. So for instance, 1 2 3 4 5 might become 3 4 5 1 2.
// Input : arr[] = {30, 40, 50, 10, 20}
//         key = 10
// Output : Found at index 3

// The binary search needs to be modified to perform the search. The idea is to create a recursive function that takes l and r as range in input and the key.

// 1) Find middle point mid = (l + h)/2
// 2) If key is present at middle point, return mid.
// 3) Else If arr[l..mid] is sorted
//     a) If key to be searched lies in range from arr[l]
//        to arr[mid], recur for arr[l..mid].
//     b) Else recur for arr[mid+1..h]
// 4) Else (arr[mid+1..h] must be sorted)
//     a) If key to be searched lies in range from arr[mid+1]
//        to arr[h], recur for arr[mid+1..h].
//     b) Else recur for arr[l..mid]

#include <iostream>
using namespace std;

// returns index of element to find in given array or -1 if not found
int search(int a[], int target, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    // if target is middle return that index
    int middle = (left + right) / 2;
    if (a[middle] == target)
        return middle;

    /* If a[left...mid] is sorted */
    if (a[left] <= a[middle])
    { //As this subarray is sorted, we can quickly check if key lies in half or other half
        if (a[left] <= target && target <= a[middle])
            return search(a, target, left, middle - 1);
        // If key not lies in first half subarray, Divide other half  into two subarrays,
        // such that we can quickly check if key lies in other half
        return search(a, target, middle + 1, right);
    }
    // If arr[l..mid] first subarray is not sorted, then arr[mid... h] must be sorted subarray
    if (a[middle] <= target && target <= a[right])
        return search(a, target, middle + 1, right);
    return search(a, target, left, middle - 1);
}
int main()
{
    int a[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int size = 8;
    int target = 11;
    int answer = search(a, target, 0, size - 1);
    if (answer != -1)
        cout << "Found at: " << answer << "\n";
    else
        cout << "Not found\n";
}