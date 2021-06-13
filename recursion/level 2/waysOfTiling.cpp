#include <iostream>
using namespace std;

//gives number of ways to tile the floor with 1x2 and 1x1 tiles.
int tiles(int n)
{
    // fibbonacci algorithm
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return tiles(n - 1) + tiles(n - 2);
}
int main()
{
    cout << tiles(4) << endl;
}