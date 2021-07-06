// Given an array of integers. Find a peak element in it. An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour.

// * example
// Input: array[]= {5, 10, 20, 15}
// Output: 20
// The element 20 has neighbours 10 and 15,
// both of them are less than 20.

// Following corner cases give better idea about the problem.

// ? corner cases
// If input array is sorted in strictly increasing order, the last element is always a peak element. For example, 50 is peak element in {10, 20, 30, 40, 50}.
// If the input array is sorted in strictly decreasing order, the first element is always a peak element. 100 is the peak element in {100, 80, 60, 50, 20}.
// If all elements of input array are same, every element is a peak element.

// ? approach
//  The idea is based on the technique of Binary Search to check if the middle element is the peak element or not. If the middle element is not the peak element, then check if the element on the right side is greater than the middle element then there is always a peak element on the right side. If the element on the left side is greater than the middle element then there is always a peak element on the left side. Form a recursion and the peak element can be found in log n time.

// * Algorithm:
// Create two variables, l and r, initialize l = 0 and r = n-1
// Iterate the steps below till l <= r, lowerbound is less than the upperbound
// Check if the mid value or index mid = (l+r)/2, is the peak element or not, if yes then print the element and terminate.
// Else if the element on the left side of the middle element is greater then check for peak element on the left side, i.e. update r = mid – 1
// Else if the element on the right side of the middle element is greater then check for peak element on the right side, i.e. update l = mid + 1

#include <iostream>
using namespace std;

// returns index of element which is peak in given is_array
// takes array of numbers, low and high index to search inside, and size of array
int peakElement(int a[], int low, int high, int size)
{

    int mid = low + (high - low) / 2; //so that integer range is satisfied

    // if element at mid is greater than previous element and also greater than next element, return this index(mid)
    //mid==0 and mid==size-1, for edge cases, when mid is first/last element
    if ((mid == 0 || a[mid - 1] <= a[mid]) && (mid == size - 1 || a[mid + 1] <= a[mid]))
        return mid;
    // else if element at mid is less than previous element, peak exists before mid,
    else if (mid > 0 && a[mid - 1] > a[mid])
        // so call for left half of array
        return peakElement(a, low, mid - 1, size);
    else
        // else call for right half of array
        return peakElement(a, mid + 1, high, size);
}

int main()
{
    int a[] = {0, 1, 2, 5, 3, 9};
    int size = 6;
    int index = peakElement(a, 0, size - 1, size);
    cout << "Peak element " << a[index] << " found at index: " << index << "\n ";
}