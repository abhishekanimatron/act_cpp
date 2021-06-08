// input
// 5 12
// 1 2 3 7 5
// output
// 2 4

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{

    int n, s;
    cin >> n >> s;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //array indexes
    int i = 0, j = 0;
    //pointers
    int start, end = -1;
    //sum of subarray
    int sum = 0;
    //while j is less than array size & the sum is less than given target 's'
    while (j < n && sum + a[j] <= s)
    {
        sum += a[j];
        j++;
    }
    // if equal print and return
    if (sum == s)
    {
        cout << i + 1 << " " << j << endl;
        return 0;
    }
    // now, here our sum is greater
    while (j < n)
    {
        // include j's value
        sum += a[j];
        // while our sum is greater, shift right index and decrease its value from the sum
        while (sum > s)
        {
            sum -= a[i];
            i++;
        }
        if (sum == s)
        {
            // one based indexing
            start = i + 1;
            end = j + 1;
            break;
        }
        j++;
    }
    cout << start << " " << end << endl;
}