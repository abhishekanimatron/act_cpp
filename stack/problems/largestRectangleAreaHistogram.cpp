#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largest(vector<int> v)
{
    stack<int> stac;
    // push last value as 0, to make it decreasing
    v.push_back(0);
    // vector size
    int n = v.size();
    int ans = 0;
    int i = 0;
    // loop till i less than size of vector
    while (i < n)
    {
        // while value at stack's top element (which is index) is greater than current element
        // means there may be answer ahead
        while (!stac.empty() && v[stac.top()] > v[i])
        {
            cout << "reached" << endl;
            // tope element (index of vector) of stack stored
            int tope = stac.top();
            // corresponding height value in vector
            int height = v[tope];
            // pop that element from stack
            stac.pop();
            // this will be if stack is empty, i gives the length of the rectangle
            if (stac.empty())
                ans = max(ans, height * i);
            // else length will be i - stack's top value, which is less than current i - 1
            else
            {
                int len = i - stac.top() - 1;
                ans = max(ans, height * len);
            }
        }
        // push the current index to stack
        stac.push(i);
        i++; //increment index value
    }
    // return maximum area as answer
    return ans;
}

int main()
{
    // vector<int> v = {2, 1, 5, 6, 2, 3};
    vector<int> v = {3, 4, 5, 6, 7};
    cout << largest(v) << endl;
    //output: 10
    // = =
    // =
    // = = = = =
    // = = = = = =
    // = =
    // = = =
    //
    //output: 16
    //
    // = = =
    // = = = =
    // = = = = =
    // = = = = = =
    // = = = = = = =
    //
    //
    //
}