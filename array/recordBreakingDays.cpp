// input
// 8
// 1 2 0 7 2 0 2 2
// output
// 2

#include <iostream>
using namespace std;

int main()
{
    int answer = 0;
    int n = 0;
    cin >> n;
    int a[n + 1];
    a[n + 1] = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxi = -10;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > maxi && a[i] > a[i + 1])
            answer++;
        maxi = a[i];
    }
    cout << answer << endl;
}