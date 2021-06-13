#include <iostream>
using namespace std;

void increasingOrder(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    increasingOrder(n - 1);
    cout << n << endl;
}
void decreasingOrder(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    cout << n << endl;
    decreasingOrder(n - 1);
}

int main()
{
    int n;
    cin >> n;
    // increasingOrder(n);
    //input: 5
    //output:
    // 1
    // 2
    // 3
    // 4
    // 5
    decreasingOrder(n);
    //input: 5
    //output:
    // 5
    // 4
    // 3
    // 2
    // 1
}