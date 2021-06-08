// input
// 7
// 4 -4 6 -6 10 -11 12
// output
// 22

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// kadane's function
int kadane(int a[], int n)
{
    int currentSum = 0;
    int maximumSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentSum += a[i];
        // if sum becomes less zero, reset it
        if (currentSum < 0)
            currentSum = 0;
        maximumSum = max(maximumSum, currentSum);
    }
    return maximumSum;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int wrapSum;
    int nonWrapSum;

    nonWrapSum = kadane(a, n);
    int totalSumOfElements = 0;
    for (int i = 0; i < n; i++)
    {
        totalSumOfElements += a[i];
        a[i] = -a[i]; //reverse sign of each number
    }
    // kadane on reverse signs will give largest subarray with value (negative originally) //non-contributing
    // which when subtracted(added since sign) from original array gives our answer on max function
    wrapSum = totalSumOfElements + kadane(a, n);
    cout << max(nonWrapSum, wrapSum) << endl;
}