#include <iostream>
using namespace std;

//gets if the position has one or zero in binary representation
int getBit(int number, int position)
{
    // (1<<position) sets 1 at that position
    return ((number & (1 << position)) != 0);
    //and with zero and it gives zero
}

//sets the given position to one binary representation
int setBit(int number, int position)
{
    //or with one and it gives one, zero gives zero at that position
    return (number | (1 << position));
}

// sets the bit at given position to zero
int clearBit(int number, int position)
{
    // ~ is used for taking one's complement
    // ~0100 = 1011
    int mask = ~(1 << position);
    //and with zero and it gives zero
    return (number & mask);
}

// update bit at given position with passed value
//this is basically clear bit and set bit with dynamic value
int updateBit(int number, int position, int value)
{
    // clear bit
    int mask = ~(1 << position);
    number = number & mask;
    //set bit according to passed value
    return (number | (value << position));
}
int main()
{
    // cout << getBit(5, 2) << endl;
    // //output: 1
    // //5 : 0101
    // cout << setBit(5, 1) << endl;
    // //output: 7
    // //5: 0101
    // //7: 0111
    // cout << clearBit(5, 2) << endl;
    // //output: 1
    // //5:0101
    // //1:0001
    cout << updateBit(5, 1, 1) << endl;
    // output: 7
    //5: 0101
    //7: 0111
}