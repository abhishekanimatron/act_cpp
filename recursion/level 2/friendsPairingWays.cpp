#include <iostream>
using namespace std;

// There are n friends, we have to find all the pairings possible. Each person can be
// paired with only one person or does not pair with anyone.
// Idea: we have two options, i’th friend does not get paired or we have n-1 options
// to pair it with anyone.
int friendPairings(int n)
{

    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    // if we not pair then n-1 choices, if paired then n-2 with n-1 options for rest
    return friendPairings(n - 1) + friendPairings(n - 2) * (n - 1);
}
int main()
{
    cout << friendPairings(3) << endl;
    //output: 4
    //1, 1-1
    //1-1, 1
    // 1,1,1
    //-1,1,1-
}