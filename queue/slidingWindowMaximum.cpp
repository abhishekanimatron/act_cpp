// input:
// 8 3
// 1 3 -1 -3 5 3 6 7

// output:
// 3 3 5 5 6 7

#include <iostream>
#include <vector>
#include <set>
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
    //greater comparator, top element is maximum
    multiset<int, greater<int>> s;

    // answer vector containing maximums of each window
    vector<int> ans;
    // for window size length insert elements in s, set
    for (int i = 0; i < k; i++)
    {
        s.insert(a[i]);
    }
    // value at beginning, in each window is its maximum we access it by * deferencing operator
    // and push that answer in our ans vector
    ans.push_back(*s.begin());
    // for rest of elements
    for (int i = k; i < n; i++)
    {
        // remove 1st occurrence of a[i-k], a[k-k], a[0], first element in set, the maximum one
        //removes 1st element in that window
        s.erase(s.lower_bound(a[i - k]));
        // insert a[i], a[k], i.e. next element after previous window
        //inserts value next to previous window
        s.insert(a[i]);
        // same as before
        ans.push_back(*s.begin());
    }
    //print output
    for (auto i : ans)
        cout << i << " ";
}
