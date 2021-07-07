// Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.
// * Example
// arr[] = {1, 4, 45, 6, 0, 19}
//    x  =  51
// Output: 3
// Minimum length subarray is {4, 45, 6}

// ? Approach
// Idea is to use a similar approach to a sliding window. Start with an empty subarray, add elements to the subarray until the sum is less than x. If the sum is greater than x, remove elements from the start of the current subarray.

// ? Algorithm
// Algorithm:

// Create three variables, l=0, sum = 0
// Traverse the array from start to end.
// Update the variable sum by adding current element, sum = sum + array[i]
// If the sum is greater than the given sum, update the variable sum as sum = sum – array[l], and update l as, l++.
// If the sum is equal to given sum, print the subarray and break the loop.
#include <iostream>
using namespace std;

int smallestSum(int array[], int size, int sumLimit)
{
    // sum of elements, minimum length of subarray
    int sum = 0, minimumLength = size + 1;
    // start and end pointers
    int start = 0, end = 0;
    // while end pointer does not exceed array size
    while (end < size)
    {
        // while sum of current elements is less than limit given, add elements, and till end doesn't exceed size of array
        while (sum <= sumLimit && end < size)
        {
            sum += array[end];
            end++;
        }
        // now that sum is greater than limit
        // while sum is greater than limit, reduce the elements from behind(start pointer), and till start doesn't exceed the size of array
        while (sum > sumLimit && start < size)
        {
            // if the distance between the end and start pointer is less than minimum length of subarray, update it
            if (end - start < minimumLength)
                minimumLength = end - start;
            // reduce start element's value from sum
            sum -= array[start];
            start++;
        }
    }
    return minimumLength;
}

int main()
{
    int array[] = {1, 4, 45, 6, 0, 19};
    int size = 6;
    int sumLimit = 51;

    int minimumLength = smallestSum(array, size, sumLimit);
    if (minimumLength == size + 1)
        cout << "No subarray exists, Whole array sum is smaller than " << sumLimit << ".\n";
    else
        cout << "Smallest length subarray is: " << minimumLength << "\n";
    // Smallest length subarray is: 3
}