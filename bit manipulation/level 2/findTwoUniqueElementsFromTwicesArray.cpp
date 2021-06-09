#include <iostream>
using namespace std;

//returns 1 if position is set in given number
int isSetBit(int number, int position)
{
    return ((number & (1 << position)) != 0);
}

// returns 2 unique integers from array which has each element twice except them
void uniqueElements(int a[], int n)
{
    //e.g.-> 5 ^ 7
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum ^ a[i];
    }
    // this will give
    // 5 ^ 7
    // 0101 ^ 0111
    // = 0010
    int temp = sum;
    // in this value we find the position of rightmost set bit, here 1
    int setBit = 0;
    int position = 0; //position of rightmost set bit
    while (setBit != 1)
    {
        setBit = sum & 1;
        position++;
        sum = sum >> 1;
    }
    // now, the elements in array which have that bit as set, we xor them
    int newSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (isSetBit(a[i], position - 1))
        {
            newSum = newSum ^ a[i];
        }
    }
    // we get new xor sum as one number we require as that will be unique, because the other unique one does not
    // have tha bit set
    cout << newSum << endl;
    // xoring with previous xor value to this answer value gives us the second unique element
    cout << (temp ^ newSum) << endl;
}

int main()
{
    int a[] = {1, 2, 3, 5, 7, 1, 2, 3};
    uniqueElements(a, 8); // output: 5 & 7
}