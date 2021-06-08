// input
// 6
// 0 -9 1 3 -4 5
// output
// 2

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{

    int n, answer;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool check[100];
    // initialize a check array with falses
    for (int i = 0; i < 100; i++)
    {
        /* code */
        check[i] = false;
    }
    // for every +ve value change value to one [true]
    for (int i = 0; i < n; i++)
    {
        // positive
        if (a[i] >= 0)
            check[a[i]] = 1;
    }
    //if the value is true print and break
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            answer = i;
            break;
        }
    }
    cout << answer << endl;
}