// input
// 7
// 10 7 4 6 8 10 11
// output
// 4

#include <iostream>
using namespace std;

int main()
{

    int n = 0;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int previousDifference = a[1] - a[0];
    int answer = 2;
    int current = 2;
    int j = 2;

    while (j < n)
    {
        if (previousDifference == a[j] - a[j - 1])
            current++;
        else
        {
            previousDifference = a[j] - a[j - 1];
            current = 2;
        }
        answer = max(answer, current);
        j++;
    }

    cout << answer << endl;
}