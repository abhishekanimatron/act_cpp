#include <iostream>
using namespace std;

//counts number of paths from starting point 's' to ending point 'e', returning count value
int countPaths(int s, int e)
{
    if (s > e)
    {
        // if starting is ahead of ending we can't go back so zero
        return 0;
    }
    if (s == e)
    {
        return 1;
    }
    int count = 0;
    //loop represents values of jumps possible taking a dice
    for (int i = 1; i <= 6; i++)
    {
        // from adding that jump to the ending position
        count += countPaths(s + i, e);
    }
    return count;
}

int main()
{
    cout << countPaths(0, 3) << endl;
    //output: 4
}