// Given an array arr[] of size N and a number K, the task is to find the length of the smallest subsequence such that the sum of the subsequence is greater than or equal to number K.

// * Example
// Input: arr[] = {2, 3, 1, 5, 6, 3, 7, 9, 14, 10, 2, 5}, K = 35
// Output: 4
// Smallest subsequence with the sum greater than or equal to the given sum K is {7, 9, 14, 10}

// ? Approach
//  This problem can be solved with the help of priority queue
// Traverse input array and insert every array element into priority queue.
// Initialize variables that holds the sum of picked element from priority queue and the variable to get the count of picked element from priority queue to 0
// Pop the elements out from the priority queue until the priority queue is not empty
// Add the element into the sum
// Increase the count because the element is picked to contribute to the total sum
// Check if the sum is greater than the given number K, If yes then stop checking and output the count.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int lengthOfSmallestSubsequence(vector<int> v, int k)
{
    priority_queue<int> pque;
    // Loop to insert all elements into
    // the priority queue
    for (int i = 0; i < v.size(); i++)
    {
        pque.push(v[i]);
    }
    // intialize sum and count of elements in subsequence which will be answer
    int sum = 0, count = 0;
    // Loop to find the smallest subsequence
    while (pque.empty() == false && sum < k)
    {
        sum += pque.top();
        pque.pop();
        count++;
    }
    // if no such subsequence exist which has larger= sum than k
    if (sum < k)
        return -1;
    return count;
}
int main()
{
    vector<int> v{2, 3, 1, 5,
                  6, 3, 7, 9,
                  14, 10, 2, 5};
    int K = 35;

    cout << lengthOfSmallestSubsequence(v, K);
    //4,
    // being 7, 9, 14, 10
}