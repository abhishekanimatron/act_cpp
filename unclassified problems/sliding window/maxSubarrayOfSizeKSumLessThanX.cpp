// Given an array of integers and a sum. We have to find sum of subarray having maximum sum less than or equal to given sum in array.

// * example
// Input : arr[] = { 1, 2, 3, 4, 5 }
//         sum = 11
// Output : 10
// Subarray having maximum sum is { 1, 2, 3, 4 }
#include <iostream>
using namespace std;

void maxSum(int array[], int size, int windowLength, int sumLimit)
{
    int sum = 0;
    int answer = 0;
    // calulate sum till first set of elements
    for (int i = 0; i < windowLength; i++)
        sum += array[i];
    // if sum is less than sum limit assign answer to that
    if (sum < sumLimit)
        answer = sum;

    // starting from size of window till array's end
    for (int i = windowLength; i < size; i++)
    {
        // remove the last element's contribution to sum
        sum = sum - array[i - windowLength];
        // add next element which is after the window (right side of window)
        sum = sum + array[i];
        // if this current sum is less than limit
        if (sum < sumLimit)
            // update answer to maximum of the two
            answer = max(answer, sum);
    }
    cout << "Max sum: " << answer << "\n";
    // Max sum: 18, from (4,6,8)
}

int main()
{
    int array[] = {7, 5, 4, 6, 8, 9};
    int size = 6;         // size of array
    int windowLength = 3; // window size, or these no. elements should contribute to sum
    int sumLimit = 20;    //sum of the elements should be less than this

    maxSum(array, size, windowLength, sumLimit);
}