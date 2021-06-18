// input:
// 6 2
// 3 4 9 1 -4 10

// output:
// 4 9 9 1 10

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int n, k; //array size, window size
    cin >> n >> k;
    int a[n];
    // take array elements input
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    deque<int> q;
    vector<int> ans;

    // for window size k
    for (int i = 0; i < k; i++)
    {
        // if the current element is greater than last element of queue, pop back, remove that smaller one
        // do that till condition is true, and not empty
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();
        // push the index to deque
        q.push_back(i);
    }
    // push front element of q to answer, which is an index in 'a' array, so an element from 'a' is pushed
    ans.push_back(a[q.front()]);
    //for rest of elements
    for (int i = k; i < n; i++)
    {
        // to remove the first element in window, i-k, k-k, 0, not part of current window
        if (q.front() == i - k)
            q.pop_front();
        //same
        // if the current element is greater than last element of queue, pop back, remove that smaller one
        // do that till condition is true, and not empty
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();

        // push the index to deque
        q.push_back(i);
        // push front element of q to answer, which is an index in 'a' array, so an element from 'a' is pushed
        ans.push_back(a[q.front()]);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
}