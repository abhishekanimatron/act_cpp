// input
// 3
// 1 2 2
// output
// 1
// 3
// 5
// 2
// 4
// 2

#include <iostream>
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
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            cout << sum << endl;
        }
    }
}