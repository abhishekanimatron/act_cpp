#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//brute force
// find left & right maximums for each element, get the minimum of those two minus the height/current element
// gives the water in that element, add to result

// {
//  int res = 0;

// For every element of the array
//     for (int i = 1; i < n-1; i++) {

// Find the maximum element on its left
//         int left = arr[i];
//         for (int j=0; j<i; j++)
//            left = max(left, arr[j]);

// Find the maximum element on its right
//         int right = arr[i];
//         for (int j=i+1; j<n; j++)
//            right = max(right, arr[j]);

// Update the maximum water
//        res = res + (min(left, right) - arr[i]);
//     }

//     return res;
// }

// o(1), s(1) //stack approach
int waterStored(vector<int> v)
{
    stack<int> stac;
    int n = v.size();
    int answer = 0;
    // for each index i of vector v
    for (int i = 0; i < n; i++)
    {
        // if stack is not empty
        // and element at index (stack.top()) is lesser than current element, this element can contribute to
        // our water container, so we include it
        while (!stac.empty() && v[stac.top()] < v[i])
        {
            int current = stac.top();
            stac.pop();
            // if after popping this, the stack becomes empty, it means no walls are enclosing on the left side of this
            // wall, (element), so we break out of loop, so as to not take this into account of our answer
            if (stac.empty())
                break;
            //else
            // the difference of current element - stack's top gives the length of container
            int length = i - stac.top() - 1;
            // values at stac.top() and i will be walls of our container - current element gives height of container
            // and multiplying that by length gives the area which is then
            // added to answer
            answer += (min(v[stac.top()], v[i]) - v[current]) * length;
        }
        // push the current index to stack
        stac.push(i);
    }
    return answer;
}

int main()
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << waterStored(v) << endl;
    // 6
}