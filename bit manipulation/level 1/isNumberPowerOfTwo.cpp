#include <iostream>
using namespace std;

bool isPowerOfTwo(int number)
{
    //edge case
    if (number == 0)
        return true;
    // any power of 2 on anding with previous number gives zero else we return true
    return !(number & number - 1);
    // this gives same bits as n except rightmost set bit
}

int main()
{
    // cout << isPowerOfTwo(14) << endl; //0
    cout << isPowerOfTwo(16) << endl; //1
    //16: 10000
    //15: 01111
}