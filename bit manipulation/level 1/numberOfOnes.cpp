#include <iostream>
using namespace std;

int countNumberOfOnes(int number)
{
    int count = 0;
    while (number)
    {
        // everytime this reduces one one bit on rightmost side, giving 0 at power of 2 number
        number = number & (number - 1);
        // n&n-1 gives same bits as n except rightmost set bit
        count++;
    }
    return count;
}

int main()
{
    cout << countNumberOfOnes(9) << endl; //2
    //9: 1001
    //8: 1000
    //0: 0000
}