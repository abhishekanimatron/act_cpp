#include <iostream>
using namespace std;

void hanoiSolver(int n, char sourceRod, char destinationRod, char helperRod)
{
    if (n == 0)
    {
        return;
    }
    hanoiSolver(n - 1, sourceRod, helperRod, destinationRod);
    cout << "Move from " << sourceRod << " to " << destinationRod << endl;
    hanoiSolver(n - 1, helperRod, destinationRod, sourceRod);
}

int main()
{
    int n;
    cin >> n;
    hanoiSolver(n, 'a', 'c', 'b');
    //input: 3
    //output :
    // Move from a to c
    // Move from a to b
    // Move from c to b
    // Move from a to c
    // Move from b to a
    // Move from b to c
    // Move from a to c
}