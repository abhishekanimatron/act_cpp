// Given that integers are being read from a data stream. Find the median of all the elements read so far starting from the first integer till the last integer. This is also called the Median of Running Integers. The data stream can be any source of data, for example, a file, an array of integers, input stream etc.

// * Example
// input: 5 10 15
// Output: 5, 7.5, 10
// Explanation: Given the input stream as an array of integers [5,10,15]. Read integers one by one and print the median correspondingly. So, after reading first element 5,median is 5. After reading 10,median is 7.5 After reading 15 ,median is 10.

// ?Approach
// Approach: The idea is to use max heap and min heap to store the elements of higher half and lower half. Max heap and min heap can be implemented using priority_queue in C++ STL. Below is the step by step algorithm to solve this problem.

// ? Algorithm
// Create two heaps. One max heap to maintain elements of lower half and one min heap to maintain elements of higher half at any point of time..
// Take initial value of median as 0.
// For every newly read element, insert it into either max heap or min-heap and calculate the median based on the following conditions:
// If the size of max heap is greater than the size of min-heap and the element is less than the previous median then pop the top element from max heap and insert into min-heap and insert the new element to max heap else insert the new element to min-heap. Calculate the new median as the average of top of elements of both max and min heap.
// If the size of max heap is less than the size of min-heap and the element is greater than the previous median then pop the top element from min-heap and insert into the max heap and insert the new element to min heap else insert the new element to the max heap. Calculate the new median as the average of top of elements of both max and min heap.
// If the size of both heaps is the same. Then check if the current is less than the previous median or not. If the current element is less than the previous median then insert it to the max heap and a new median will be equal to the top element of max heap. If the current element is greater than the previous median then insert it to min-heap and new median will be equal to the top element of min heap.

#include <iostream>
#include <queue>
using namespace std;

// double since medians can be decimaled~
// function to calculate med of stream
void printMedians(double arr[], int n)
{
    // max heap to store the smaller half elements
    priority_queue<double> sm;
    // min heap to store the greater half elements
    priority_queue<double, vector<double>, greater<double>> gr;

    // take first element as median and push to maxheap
    double median = arr[0];
    sm.push(median);
    //print first median
    cout << median << "\n";
    /*  At any time we try to make heaps balanced and
        their sizes differ by at-most 1. If heaps are
        balanced,then we declare median as average of
        min_heap_right.top() and max_heap_left.top()
        If heaps are unbalanced,then median is defined
        as the top element of heap of larger size  */
    // reading elements of stream one by one, from 2nd element
    for (int i = 1; i < n; i++)
    {
        double x = arr[i]; //store in x
        // if max heap has more elements than min heap
        if (sm.size() > gr.size())
        {
            if (x < median) //if this element is smaller than our median
            {
                gr.push(sm.top()); //take top element of max heap and push it to min heap
                sm.pop();          //remove that element from max heap
                sm.push(x);        //push current element to max heap, making its size equal to min heap
            }
            else
                // if current is element is greater than median push it to min heap(greater half elements)
                gr.push(x);
            // calulate median again, since now elements are equal, making it even, calculate average of 2
            median = (sm.top() + gr.top()) / 2.0;
        }
        // if min heap has max elements than min heap
        else if (sm.size() < gr.size())
        {
            if (x > median) //if this element is greater than our median
            {
                sm.push(gr.top()); //take top element of min heap and push it to max heap
                gr.pop();          //remove that element from min heap
                gr.push(x);        //push current element to min heap, making its size equal to max heap
            }
            else
                // if current is element is smaller than median push it to max heap(smaller half elements)
                sm.push(x);
        }
        // if both max and min heap have equal size
        else
        {
            if (x < median)
            {
                // if current element is smaller than median, push to max heap
                sm.push(x);
                //median will be top of max heap
                median = (double)sm.top();
            }
            else
            {
                // if current element is greater than median, push to min heap
                gr.push(x);
                //median will be top of min heap
                median = (double)gr.top();
            }
        }
        cout << median << "\n";
    }
}

int main()
{
    double arr[] = {10, 15, 21, 30, 18, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMedians(arr, n);
    // 10
    // 12.5
    // 15
    // 15
    // 18
    // 18
    return 0;
}