// Given k sorted arrays of possibly different sizes, merge them and print the sorted output.
//* Example:

// Input: k = 3
//       arr[][] = { {1, 3},
//                   {2, 4, 6},
//                   {0, 9, 10, 11}} ;
// Output: 0 1 2 3 4 6 9 10 11

//? Approach
// An efficient solution is to use heap data structure. The time complexity of heap based solution is O(N Log k).
// 1. Create an output array.
// 2. Create a min heap of size k and insert 1st element in all the arrays into the heap
// 3. Repeat following steps while priority queue is not empty.
// …..a) Remove minimum element from heap (minimum is always at root) and store it in output array.
// …..b) Insert next element from the array from which the element is extracted. If the array doesn’t have any more elements, then do nothing.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//  A pair of pairs, first element is going to store value, second element index of array
// from which it belongs to and third element index in that array.
typedef pair<int, pair<int, int>> ppi;

//This function takes an array of arrays as an
// argument and all arrays are assumed to be
// sorted. It merges them together and prints
// the final sorted output.
vector<int> mergeKArrays(vector<vector<int>> arr)
{
    vector<int> output; //output array

    // Create a min heap with k heap nodes. Every
    // heap node has first element of an array
    priority_queue<ppi, vector<ppi>, greater<ppi>> que;

    // for our example from 0 till less than 3
    for (int i = 0; i < arr.size(); i++)
        // push each array's first element to min heap
        que.push({arr[i][0], {i, 0}});

    // Now one by one get the minimum element
    // from min heap and replace it with next
    // element of its array, till our min heap becomes empty
    while (que.empty() == false)
    {
        // take the first element from heap, which is always minimum
        ppi current = que.top();
        que.pop(); //remove that element

        int arrayNumber = current.second.first;
        int indexInArray = current.second.second;

        // push the value of element to output array
        output.push_back(current.first);
        // insert next element from the array from which this element as popped off
        // if it exists, that is index+1 is less than size of that array
        if (indexInArray + 1 < arr[arrayNumber].size())
            que.push({arr[arrayNumber][indexInArray + 1], {arrayNumber, indexInArray + 1}});
    }
    return output;
}

int main()
{
    // 3 arrays to be merged to one sorted array taken as two-dimension vector
    vector<vector<int>> arr{
        {2, 6, 12},
        {1, 9},
        {23, 34, 90, 200},
    };
    // ouput vector has all arrays merged as single sorted array
    vector<int> output = mergeKArrays(arr);
    cout << "Merged:\n";
    for (auto i : output)
        cout << i << " ";
    cout << "\n";
    //     Merged:
    // 1 2 6 9 12 23 34 90 200
}