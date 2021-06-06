#include <iostream>
using namespace std;
int main()
{
    int n, rev = 0;
    cin >> n;

    while (n > 0)
    {
        int last = n % 10;
        rev = rev * 10 + last;
        n /= 10;
    }
    cout << rev << endl;
}