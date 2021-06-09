#include <iostream>
using namespace std;

// returns true if the value at position in number is 1
bool getBit(int number, int position)
{
    return ((number & (1 << position)) != 0);
}

// set that postion in given number to one
int setBit(int number, int position)
{
    return (number | (1 << position));
}
//array, array size
int uniqueNumber(int a[], int n)
{
    int answer = 0;
    // we assume integer takes 64 bit space, so all bits in integer representation are covered
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        // set sum to number of elements which have index i as set
        for (int j = 0; j < n; j++)
        {
            if (getBit(a[j], i))
            {
                // if that position is set
                sum++;
            }
        }
        // if that isn't divisible by 3 then we set that position in our answer to 1
        // reading that in binary format will give our answer
        if (sum % 3 != 0)
        {
            answer = setBit(answer, i);
        }
    }
    return answer;
}

int main()
{
    int a[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 9};
    cout << uniqueNumber(a, 10) << endl;
    //output: 9
}