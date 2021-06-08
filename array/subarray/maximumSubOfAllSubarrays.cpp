// input
// 6
// 1 -4 3 -7 4 1
// output
// 5
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int maximumSum = INT_MIN;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // // Brute Force
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         int sum = 0;
    //         for (int k = i; k <= j; k++)
    //             sum += a[k];
    //         maximumSum = max(sum, maximumSum);
    //     }
    // }

    // // Prefix sum, cumulative
    // int cumulativeSum[n + 1];
    // cumulativeSum[0] = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     // creating cumulative sum array
    //     cumulativeSum[i] = a[i - 1] + cumulativeSum[i - 1];
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     int sum = 0;
    //     for (int j = 1; j <= i; j++)
    //     {
    //         sum = cumulativeSum[i] - cumulativeSum[j - 1];
    //         maximumSum = max(maximumSum, sum);
    //     }
    // }

    // Kadane's algorithm
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += a[i];
        // if sum becomes less zero, reset it
        if (currentSum < 0)
            currentSum = 0;
        maximumSum = max(maximumSum, currentSum);
    }

    cout << maximumSum << endl;
}