// input
// 7
// 1 5 3 4 3 5 6
// output
// 2

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // cout << a[n - 1] << endl;
    int idx[100];
    for (int i = 0; i < 100; i++)
    {
        /* code */
        idx[i] = -1;
    }
    int minidx = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (idx[a[i]] != -1)
        {
            minidx = min(minidx, idx[a[i]]);
        }
        else
        {
            idx[a[i]] = i;
        }
    }
    if (minidx == INT_MAX)
        cout << "no" << endl;
    else
    {
        cout << minidx + 1 << endl;
    }
    // cout << n << endl;
}