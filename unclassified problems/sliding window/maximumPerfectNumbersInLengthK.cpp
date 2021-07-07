// Given an array arr[ ] consisting of N integers, the task is to determine the maximum number of perfect Numbers in any subarray of size K.

// A number is a perfect number if is equal to sum of its proper divisors, that is, sum of its positive divisors excluding the number itself. Write a function to check if a given number is perfect or not.
//example 6:
// Divisors of 6 are 1, 2 and 3. Sum of
// divisors is 6

//  *Example
// Input: arr[ ] = {28, 2, 3, 6, 496, 99, 8128, 24}, K = 4
// Output: 3
// Explanation: The sub-array {6, 496, 99, 8128} has 3 perfect numbers which is maximum.

// ? Approach
// To optimize approach, convert the given array arr[ ] into a binary array where the ith element is 1 if it is a Perfect Number. Otherwise, the ith element is 0. Therefore, the problem reduces to finding the maximum sum subarray of size K in the binary array using the Sliding Window technique. Follow the steps below to solve the problem:

// Traverse the array and for each element of the array arr[], check if it is a Perfect Number or not.
// If arr[i] is a Perfect Number then convert arr[i] equal to 1. Otherwise, convert arr[i] equal to 0.
// To check if a number is a perfect number or not:
// Initialize a variable sum to store the sum of divisors.
// Traverse every number in the range [1, arr[i] – 1] and check if it is a divisor of arr[i] or not. Add all the divisors.
// If the sum of all the divisors is equal to arr[i], then the number is a perfect number. Otherwise, the number is not a Perfect Number.
// Compute the sum of the first subarray of size K in the modified array.
// Using the sliding window technique, find the maximum sum of a subarray from all possible subarrays of size K

#include <iostream>
#include <cmath>
using namespace std;
// Function to check a number is Perfect Number or not
int isPerfectNumber(int n)
{
    // stores sum of divisors
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // if square is not equal to number itself, add that number and n/i
            if (i * i != n)
                sum = sum + i + n / i;
            else
                sum = sum + i;
        }
    }
    // check if sum of divisors is equal to n
    if (sum == n && n != -1)
        return 1;
    return 0;
}

// Function to return maximum sum of a subarray of size K
int maxSum(int arr[], int n, int k)
{
    if (n < k)
    {
        cout << "Invalid.\n";
        return -1;
    }
    // calculate sum of first window
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    // Compute sums of remaining windows by removing first element of previous
    //  window and adding last element of current window
    int currentSum = sum;
    for (int i = k; i < n; i++)
    {
        currentSum += arr[i] - arr[i - k];
        sum = max(sum, currentSum);
    }
    return sum;
}

int maximumPerfectNumbersSubarray(int arr[], int n, int k)
{
    // The given array is converted into binary array
    for (int i = 0; i < n; i++)
    {
        // if perfect make it 1, else 0
        arr[i] = isPerfectNumber(arr[i]) ? 1 : 0;
    }
    return maxSum(arr, n, k);
}

int main()
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int K = 4;
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << maximumPerfectNumbersSubarray(arr, N, K);
    //3
}