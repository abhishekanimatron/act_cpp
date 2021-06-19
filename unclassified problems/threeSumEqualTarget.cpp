#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// input:
// 6
// 24
// 12 3 6 9 34 25

// output:
// Found sum

// input:
// 6
// 24
// 1 3 6 9 34 25

// output:
// Not found sum

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int targetSum;
    cin >> targetSum;
    // for input we add '&'
    for (auto &i : v)
        cin >> i;

    bool found = false; //flag
    sort(v.begin(), v.end());
    //two pointer approach for each element
    for (int i = 0; i < n; i++)
    {
        //high low pointers
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int currentSum = v[i] + v[low] + v[high];
            if (currentSum == targetSum)
                found = true;
            if (currentSum < targetSum)
                low++;
            else
                high--;
        }
    }
    if (found)
        cout << "Found sum" << endl;
    else
        cout << "Not found sum" << endl;
}