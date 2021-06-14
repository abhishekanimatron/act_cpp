//normalize array by replacing the rank of the element in sorted array, using comparator of sort function

// input: 10, 16, 7, 14, 5, 3, 2, 9
// output: 5 7 3 6 2 1 0 4

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// compare function, takes two pairs, and returns true if first value (element's value)
// of 1st pair is less than 2nd pair's first value(element's value)
bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    int a[] = {10, 16, 7, 14, 5, 3, 2, 9};

    // vector v of pairs (int, int)
    vector<pair<int, int>> v;

    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
    {
        // push the element and its index as a pair in our vector 'v'
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end(), comparator);

    for (int i = 0; i < v.size(); i++)
    {
        // second value in our vector stores indexes of original array, in that index we store i's in ascending order
        // forming the same array with normalized values
        a[v[i].second] = i;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
