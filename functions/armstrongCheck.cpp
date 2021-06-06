#include <iostream>
using namespace std;
int main()
{
    int n, arm = 0;
    cin >> n;
    int temp = n;
    while (temp > 0)
    {
        int last = temp % 10;
        arm = arm + last * last * last;
        temp /= 10;
    }
    if (arm == n)
        cout << "armstrong" << endl;
    else
        cout << "no" << endl;
}